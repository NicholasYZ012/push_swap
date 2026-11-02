*This project has been created as part of the 42 curriculum by nilim and juho*

# push_swap

## Description

**push_swap** sorts a list of integers using only two stacks (`a` and `b`) and a
fixed set of 11 operations. The program prints the list of operations that sorts
stack `a` in ascending order (smallest number on top), one operation per line.

The goal of the project is to make algorithmic complexity concrete: the same
input can need a handful of moves or tens of thousands of moves depending on the
algorithm picked. The binary therefore embeds **four strategies** and can choose
between them at runtime based on how unsorted the input is (its *disorder*):

| Strategy | Flag | Complexity (in push_swap operations) | Technique |
|---|---|---|---|
| Simple | `--simple` | O(n²) | selection sort (push the smallest to `b`, pull everything back) |
| Medium | `--medium` | O(n√n) | bucket / chunk sort with buckets of width 2√n |
| Complex | `--complex` | O(n log n) | LSD radix sort on ranks (binary) |
| Adaptive | `--adaptive` (default) | depends on disorder | picks one of the three above |


---

## Instructions

### Build

```sh
make        # builds libft, then ./push_swap
make clean  # removes object files
make fclean # removes objects and the binary
make re     # fclean + all
```

Compiled with `cc -Wall -Wextra -Werror`. No bonus rule is provided: this repo
does not contain our own `checker`.

### Run

```sh
./push_swap [--bench] [--simple | --medium | --complex | --adaptive] <int> <int> ...
```

- The first number is the **top** of stack `a`.
- Flags must come **before** the numbers. `--bench` and one strategy
  flag can each be given once, in any order.
- No arguments → prints nothing and returns.
- Invalid input (not an integer, outside the `int` range, duplicates, a flag
  after the numbers, an unknown flag) → prints `Error` on **stderr**.
- No strategy flag = `--adaptive`.

| Flag | Effect | Output goes to |
|---|---|---|
| `--simple` / `--medium` / `--complex` / `--adaptive` | force a strategy | – |
| `--bench` | after sorting, print disorder %, strategy + complexity class, total ops and per-operation counts | **stderr** |

### Examples

```sh
$ ./push_swap 3 2 1
sa
rra

$ ./push_swap --bench 5 4 3 2 1 > /dev/null
[bench] disorder: 100.00%
[bench] strategy: Adaptive / O(n log n)
[bench] total_ops: 8
[bench] sa: 1 sb: 0 ss: 0 pa: 2 pb: 2
[bench] ra: 0 rb: 0 rr: 0 rra: 3 rrb: 0 rrr: 0

$ ./push_swap 1 1 2
Error
```

### Verify with the checker

```sh
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG     # OK / KO
./push_swap $ARG | wc -l                    # number of operations
```


---

## How it works

### Stacks and operations

- Each stack is a singly linked list (`t_stack`) with `isempty`, `push`, `pop`
  and `peek`.
- The 11 operations (`sa sb ss pa pb ra rb rr rra rrb rrr`) are built on four
  primitives: swap, push, rotate, reverse rotate.
- Every operation goes through one function, `ops()`. It performs the move,
  increments that operation's counter (`t_opctr`) and prints it. That is why
  `--bench` is always exact: it reads the same counters.
  An operation that does nothing (e.g. `sa` on a 1-element stack) is not counted
  or printed.

### Parsing and ranking

1. Flags are read from the start of `argv`.
2. Every other argument must be a valid `int` (overflow-checked) with no duplicates.
3. Values are replaced by their **rank** (`0 … n-1`) and stack `a` is filled with
   ranks. The sorting algorithms therefore never deal with negative numbers or
   large gaps, and radix sort can work on bits.

### Disorder metric

Measured once, **before any move**, over every pair `(i < j)` in `a`:

```
disorder = (pairs where a[i] > a[j]) / (all pairs)
```

`0.0` = already sorted, `1.0` = reverse order, ~`0.5` = random.
Computed in O(n²) time during parsing.

### Tiny inputs

- Already sorted → no output.
- 2 numbers → `sa`.
- 3 numbers → hard-coded case table, at most 2 operations.
- ≤ 5 numbers (`SMALL_N`) → every strategy falls back to the selection sort
  (3-number table for the last three). Worst case for 5 numbers: 10 operations.

---

## Algorithms and justification

### 1. Simple – selection sort, O(n²)

Repeat `n-3` times: rotate `a` (with `ra` or `rra`, whichever is shorter) until
the smallest remaining rank is on top, then `pb`. Sort the last 3 with the case
table, then `pa` everything back. `b` receives ranks in increasing order, so it
is in descending order from the top and each `pa` lands on something bigger.

- **Time:** each of the `n-3` rounds costs ≤ ⌊n/2⌋ rotations + 1 push, plus
  `n-3` pushes back → ≤ n·(n/2 + 2) = **O(n²)**.
- **Space:** O(1) extra besides the two stacks.
- **Why selection sort (juho):** I first chose bubble sort because it is the most
  basic and the easiest to implement. After seeing several of my peers struggle to
  optimize bubble sort enough to reach the required operation counts, I switched to
  selection sort: it is straightforward and relatively easy to implement, and it
  is also a good fit for very small stacks.

### 2. Medium – bucket sort, O(n√n)

Ranks are split into consecutive buckets of width `2·⌊√n⌋`
(≈ √n / 2 buckets). The 3 largest ranks always stay in `a`.

1. **Phase 1:** for each bucket, from the smallest ranks up, repeatedly find the
   bucket member *nearest* to the top of `a` (looking both from the top and the
   bottom), rotate it up with `ra`/`rra`, `pb`.
2. **Phase 2:** sort the 3 left in `a`, then for rank `n-4` down to `0` rotate `b`
   (`rb`/`rrb`, shortest way) until that rank is on top and `pa`.

- **Time (phase 1):** a bucket has Θ(√n) members spread over the stack, so
  picking the nearest member each time costs about one sweep (O(n) rotations) per
  bucket in total → √n buckets × O(n) = **O(n√n)** for typical (random) input.
  We have not proved a tight worst case for adversarial placements.
- **Time (phase 2):** `b` is made of buckets, the last pushed on top. The next
  largest rank is always in the current bucket or the one next to it, so it is at
  most ~2 bucket widths away: O(√n) per `pa` × n = **O(n√n)**.
- **Space:** O(1) extra besides the stacks.
- **Why bucket sort (juho):** it lets me make full use of my ranking function
  (buckets are just rank ranges), and out of the available options it seemed the
  most reasonable and the easiest to understand. Peers who had used this algorithm
  also gave it good reviews and taught me how to implement it properly.
- **Why `2√n`:** wider buckets make phase 2 expensive (more to search in `b`),
  narrower buckets make phase 1 do more sweeps. The bucket size was tuned by hand
  to save moves (commit `208450c`) and `2√n` is the width we kept.


### 3. Complex – LSD radix sort, O(n log n)

Works on ranks, one bit at a time from the least significant bit. For each bit:
go through all `n` numbers of `a`; if the bit is `0` → `pb`, else → `ra`. Then
`pa` everything back. Because ranks are `0 … n-1`, the number of passes is the
bit length of `n` (7 for 100 numbers, 9 for 500).

- **Time:** per pass ≤ n (pb/ra) + n (pa) = 2n operations; passes =
  ⌊log₂ n⌋ + 1 → ≤ 2n(⌊log₂ n⌋ + 1) = **O(n log n)**.
- **Space:** O(1) extra besides the stacks.
- **Note:** the operation count does not depend on the order of the input, only
  on `n` (always 1084 for n = 100, 6784 for n = 500 in our runs).

### 4. Adaptive – chooses by disorder

| Disorder | Method | Class |
|---|---|---|
| `< 0.2` | Simple (selection) | O(n²) |
| `0.2 ≤ d < 0.5` | Medium (bucket) | O(n√n) |
| `≥ 0.5` | Complex (radix) | O(n log n) |

- **Thresholds:** `0.2` and `0.5` are the regime boundaries given in the subject.
  The method behind each regime is our own choice.
- **Complexity of the whole:** the cost is that of the chosen method, so the
  adaptive result is bounded by O(n²) / O(n√n) / O(n log n) in the three regimes
  respectively. Space is O(n) for the stacks and the rank arrays.
- **Why these methods:** a nearly sorted stack means few pairs are wrong, so the
  cheap, low-overhead selection sort is acceptable; a random stack (disorder ≈ 0.5)
  is where the bucket and radix methods pay off.

---

## Performance

Measured on random inputs (distinct values). Operation counts:

| n | Strategy | min | avg | max | runs |
|---|---|---|---|---|---|
| 100 | simple | 1295 | 1459 | 1635 | 30 |
| 100 | medium | 679 | 734 | 825 | 30 |
| 100 | complex | 1084 | 1084 | 1084 | 30 |
| 100 | adaptive | 671 | 926 | 1084 | 30 |
| 500 | simple | 31230 | 32303 | 33400 | 15 |
| 500 | medium | 7012 | 7369 | 7616 | 15 |
| 500 | complex | 6784 | 6784 | 6784 | 15 |
| 500 | adaptive | 6784 | 7061 | 7637 | 15 |

Subject targets: 100 numbers → `< 2000` pass, `< 1500` good, `< 700` excellent;
500 numbers → `< 12000` pass, `< 8000` good, `< 5500` excellent.

The default (adaptive) mode is in the **good** tier for both sizes in these runs
(max 1084 for n = 100, max 7637 for n = 500). It does not reach *excellent*
(700 / 5500) yet.

---

## Project layout

| File | Content |
|---|---|
| `push_swap.c` | `main`, strategy dispatch, `--bench` reporting |
| `parser.c` | flag parsing, validation, disorder metric |
| `ps_utils.c` | `ft_atoi` with error check, ranking, `ft_sqrt`, free helpers |
| `stackops.c`, `sortops.c` | stack primitives; swap / push / rotate / reverse rotate |
| `ops.c` | the 11 operations: execute, count, print |
| `simple_sort.c`, `small_sort.c` | selection sort, 3-number table |
| `medium_sort.c`, `medium_utils.c` | bucket sort and its helpers |
| `complex_sort.c` | radix sort |
| `benchmark.c` | `--bench` output, total operation count |
| `libft/` | our libft |

---

## Contributions

Both learners understand and can explain every part of the code. Split of the
work, based on the Git history (`git log --author=...`):

| Area | nilim (NicholasYZ) | juho (Jun Hong) |
|---|---|---|
| Repository setup | initial repo, libft import, `Makefile`, README skeleton | `.gitignore`, Makefile fixes (relink / dependency issues) |
| Stacks | stack framework (`push`, `pop`, `peek`, `isempty`), the `t_vars` "bank" struct | `pop` safe on empty / missing stack |
| Operations | swap / push / rotate / reverse-rotate primitives (`sortops.c`), operation counters (`t_opctr`) | `ops()` master function first version, fixes for `ss` printing `sb` and for double operations skipping stack `b` |
| Utilities | notes on ranking, review of utils | `ft_atoi_push_swap` (overflow-checked), `ft_sqrt`, **ranking** function and its optimization |
| Parsing | `parser.c`, strategy flags (`--simple/--medium/--complex/--adaptive`), `--bench` flag, error handling and the segfault fix on invalid input | `strat_checker` fix so `--bench` followed by extra letters is rejected, disorder-pair fix, `calloc` for the counters in `main` |
| Disorder metric | implementation and first fixes | second fix of the pair counting |
| **Simple** sort | – | **selection sort** (`simple_sort.c`), `sort_three` / small-input handling (`small_sort.c`) |
| **Medium** sort | typo fix | **bucket sort** (`medium_sort.c`, `medium_utils.c`), bucket-size tuning, removed the `rr` merge optimization to keep the algorithm easy to explain |
| **Complex** sort | **radix sort** (`complex_sort.c`), several optimization / line-count passes | small Norm cleanup |
| **Adaptive** | thresholds and dispatch on disorder | – |
| Benchmark | `--bench` output (`benchmark.c`) | fixed missing `0` in the percentage |

Debugging, Norm fixes and cross-checking of each other's code were done together.


## Resources

**References**

visualizer: https://push-swap42-visualizer.vercel.app

Initial idea for simple algo and overall understanding of push swap: https://medium.com/@ayogun/push-swap-c1f5d2d41e97


Others from my wonderful peer

**Use of AI**

> - Fine tuning of the algorithms
> - Optimization recommendation
> - Testing and simulations, eg. to fine the most efficient bucket size
