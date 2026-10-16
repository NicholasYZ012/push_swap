# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

A 42 School group project (`push_swap`) built by two learners (nilim and juho). It sorts a stack of integers using only two stacks (`a` and `b`) and a limited instruction set (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`), printing the shortest possible sequence of operations to stdout.

This version of the subject (see `en.subject (2).pdf` in the repo root) is an extended variant: the binary must embed **four** sorting strategies selectable at runtime, plus a disorder metric and a benchmark mode. See "Status" below for what is and isn't done yet.

## Build commands

```bash
make        # builds libft (via its own Makefile), then push_swap
make re     # fclean + all
make clean  # removes .o files (not libft's)
make fclean # clean + removes the push_swap binary (currently does NOT clean libft.a — see gotcha below)
```

There is no test suite or linter target. 42 Norm compliance is checked with `norminette <file>.c` (must report `OK!` — a single norm error in **any** file, including bonus files, zeroes the whole grade). Compile with `-Wall -Wextra -Werror` (already the Makefile's `CFLAGS`); a build must produce zero warnings.

There's no `checker` binary yet (bonus part, see below) — when it exists, manually verify a push_swap run with:
```bash
./push_swap 2 1 3 6 5 8 | ./checker_linux 2 1 3 6 5 8   # expect "OK"
```

**Known Makefile gotcha:** `fclean`'s `rm $(NAME)` has no `-f`, so it errors if the binary was never built. `libft/libft.a` is only rebuilt via the `libft` target's `$(MAKE) libonly -C ./libft/`, which does not get triggered by `re`/`fclean` at the top level — if you're chasing a stale-libft bug, `make -C libft/ clean && make` clears it.

## Architecture

### Stack representation
`t_stack` (in `push_swap.h`) is a **custom** singly linked list (`int content`, `struct s_stack *next`) — it does *not* reuse libft's `t_list` (which stores `void *content`). The project has its own minimal list ops rather than libft's `ft_lst*` family:
- `push` / `pop` / `peek` / `isempty` (`stackops.c`) — stack-level operations; `push` mallocs the node itself (the old `ps_lstnew.c` / `ps_lstadd_front.c` files are gone). `push(t_stack **stack, int n)` takes a raw `int`, not a string. `peek` takes the `t_stack *` directly (not a double pointer).

Top of stack = head of the list (index 0).

### File responsibilities
- `push_swap.h` — all typedefs and prototypes; the single header for the whole project.
- `stackops.c` — stack primitives (`push`, `pop`, `peek`, `isempty`).
- `ps_utils.c` — free-standing helpers used to build the algorithm: `ft_sqrt` (integer sqrt, for `--medium`'s O(n√n) chunking), `ft_atoi_push_swap` (arg parsing with overflow/error detection via an `int *error` out-param, since libft's `ft_atoi` can't signal errors), `ranking` (see below), `free_stack`.
- `sortops.c` — the raw instruction primitives, which only move data and print nothing: `s(t_stack *)` swap top two, `p(&dst, &src)` move top of src onto dst (so `pb` is `p(&b, &a)`), `r(&stack)` rotate up, `rr(&stack)` rotate down. Each returns `1` if it moved something, `0` if it was a no-op (NULL/empty/single-element stack).
- `ops.c` — `ops(t_vars *bank, int op)` is what algorithms should call. `op` is one of the `SA..RRR` defines in `push_swap.h`; it runs the matching primitive on `bank->a`/`bank->b` and prints the instruction name (`sa\n`, ...) only if the primitive returned 1. `ss`/`rr`/`rrr` go through the static `both()` helper, which counts if at least one stack moved. Never call `s/p/r/rr` directly from an algorithm or nothing gets printed.
- `push_swap.c` — `main()`. **Still a smoke test**: `return 0` on no args, sets `bank.ncount = argc - 1`, calls `parser`, then prints `nice`/disorder/peek via `printf` and frees. It does not dispatch to any sort strategy yet and does not print `Error` itself (the parser does).
- `parser.c` — `parser(bank, argv)`: runs `strat_checker` twice to consume up to two leading flags (`--bench` first, then one of `--simple/--medium/--complex/--adaptive`; sets `bank->strat` bits `SMP/MED/CPX/ADP/BCH` and decrements `ncount` per strategy flag), then `fill_nums` (range/format via `ft_atoi_push_swap`), `has_duplicates`, `ranking`, pushes **ranks** (not raw values) onto `a` so `a` holds 0..n-1, and computes `disorder` with the static `calc_disorder`. Prints `Error\n` to **stderr** and returns 0 on failure. Known rough edges: `strat_checker` uses `ft_strnstr` prefix matching (`--simplefoo` passes), `argv++` inside it only changes a local copy, and `--bench` doesn't decrement `ncount` (so `--bench` alone breaks the count); `--bench` + strategy flag order is fixed.
- `simple_sort.c` — `stack_size`, `find_pos`, `bring_to_top` (cheapest `ra`/`rra` to bring a rank to the top of a), and `simple_sort` (is_sorted → size 2 → `sa`, else `sort_small`). Expects `a` to hold ranks.
- `small_sort.c` — `is_sorted`, `sort_three` (hardcoded, max 2 moves), `sort_small` (selection sort: `pb` ranks 0..size-4, `sort_three`, `pa` everything back). This is the current `--simple` implementation (O(n²)).
- `complex_sort.c` — `complex_sort`, a **first, unfinished** binary radix sort attempt (nic's). Does not work yet: it pushes `PA` instead of `PB`, `curr` is uninitialised before the loop, the `curr` loop never advances/reads past the stack, and the digit-count (`ncount /= 2`) may skip a bit. Not safe to call.
- `medium_sort.c` — untracked, **not in the Makefile `SRCS`** (so not compiled/linked); currently just an empty `medium_sort(t_vars *)` stub (juho's to write).
- `libft/` — vendored libft with its own Makefile; the top-level Makefile calls `make libonly -C ./libft/` to build `libft.a` before linking.

### The ranking algorithm (`ps_utils.c`)
`ranking(int *nums, int *rank, int size)` assigns each value in `nums` its rank (0 = smallest, size-1 = largest) by pairwise comparison, writing results into caller-allocated `rank`. It's O(n²) but does each pair only once (`j` starts at `i + 1`, not `0`), so it's ~half the comparisons of the naive double-loop version. This turns arbitrary/negative ints into a dense small range — the building block for the sort algorithms; `parser` pushes these ranks onto `a`, so every algorithm sorts ranks 0..n-1. It assumes **no duplicate values** in `nums`; `parser` runs `has_duplicates` first.

## Status

Done:
- argv parsing: int range/format check, duplicate check, `Error\n` on stderr, no-args → no output (in `main`).
- Strategy/bench flag parsing into `bank->strat` (untested — last commit says "Havent check yet").
- Disorder metric (`calc_disorder` in `parser.c`, stored in `bank->disorder` as a 0–1 float).
- `--simple` core (`simple_sort` / `sort_small` selection sort) — not reachable from `main` yet.

Still missing, per `en.subject (2).pdf`:
- `main()` dispatch: call the right strategy from `bank.strat`; default to adaptive when no strategy flag.
- Each strategy has a specific complexity class **measured in number of push_swap operations generated**, not classical algorithmic complexity:
  - `--simple`: O(n²)
  - `--medium`: O(n√n) — `ft_sqrt` exists for this; `medium_sort.c` is an empty stub
  - `--complex`: O(n log n) — `complex_sort.c` is a broken first attempt
  - `--adaptive` (default): picks technique from disorder (`< 0.2` → O(n²) regime, `0.2–0.5` → O(n√n), `≥ 0.5` → O(n log n)) — not started
- `--bench` output (stderr-only: disorder %, strategy name + complexity class, total op count, per-operation-type counts). `ops()` has no counters yet; they'd need to live in `t_vars`.
- Bonus: a `checker` program (separate binary, own Makefile `bonus` rule, `_bonus.{c,h}` files) that reads operations from stdin and replays them against an argv-supplied stack, printing `OK`/`KO`/`Error`. Only evaluated if the mandatory part is fully passing.
- `README.md` currently only has a Description-ish blurb and a commented-out task split; it's missing the required first line format (`*This project has been created as part of the 42 curriculum by <login1>, <login2>*`), Instructions, Resources (incl. AI usage disclosure), and algorithm justification sections required by the subject.
- Makefile: `medium_sort.c` not in `SRCS`; no `bonus` rule.

## Team split (from README.md, commented out)

- **Nic** (login `nilim`; owns the files with the `nilim` 42 header): stack a/b core, the 11 operations, disorder metric, complex + adaptive algorithms, argv/error handling, strategy selection.
- **juho** (Jun): ranking, simple + medium algorithms, benchmark mode, bonus checker.
