# Copilot instructions for KRCPL

Purpose
- Repository: personal solutions and example programs for "The C Programming Language" (Kernighan & Ritchie, 2nd ed.).
- Contents are standalone C programs and small tools, focused on chapters 1–4.

Quick commands
- Build everything: `make` (this repo uses a lowercase `makefile`).
- Build a single program: `make build/<program>` e.g. `make build/exercise4-01`.
- Run a program: `./build/<program>` e.g. `./build/hello`.
- Clean build artifacts: `make clean`.
- Override compiler/flags: `make CC=clang CFLAGS="-O2 -Wall"`.

Notes about tests and linting
- No dedicated test runner or linting config present.
- Use your system C tools (gcc/clang, cppcheck, splint) manually if needed.

High-level architecture
- Flat source layout: each exercise or example is a single .c file at repo root.
- Build outputs are placed in `build/` (created by the makefile).
- Each source is intended to be a self-contained program (has its own main or example harness).
- Default toolchain: gcc (CC) with default CFLAGS `-Wall -g` and LDFLAGS `-lm` (math lib); code targets portable C (C89/C90 style).

Key conventions specific to this repo
- Filenames: `exercise<chapter>-<num>.c` for K&R exercises; other utilities use short descriptive names (e.g., `grep.c`, `wc.c`).
- Makefile pattern: the makefile generates `build/<basename>` from `<basename>.c` using a generic pattern rule — rely on that when adding files.
- Minimal dependencies: prefer no external libraries; link `-lm` only when required.
- Do not expect exercise problem statements in this repo (copyright).

What to include in AI suggestions
- When proposing edits, keep changes small and localized: these are learning examples; prefer clarity over clever micro-optimizations.
- If adding new files, update README or add a short comment header in the new .c file describing the exercise number and intent.

Files/configs checked and incorporated
- README.md (used to extract build instructions and project intent)
- makefile (lowercase) — used for build targets

If you want this file improved (language, extra sections, CI integration, or suggested linters), say which areas to expand.
