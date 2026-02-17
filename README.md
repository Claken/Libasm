# LIBASM

A 42 school project focused on rebuilding key libc functions in x86_64 assembly (NASM) and packaging them into a static library.

## 👩🏻‍🏫 What I gained from the project

This project helped me strengthen low-level programming fundamentals by reimplementing standard C library behaviors in x86_64 assembly with NASM. I learned how C and assembly interact through the System V ABI, how to handle return values and `errno` correctly for syscalls, and how to structure/reuse an assembly static library from C tests.

Implemented functions:
- `ft_strlen`
- `ft_strcpy`
- `ft_strcmp`
- `ft_write`
- `ft_read`
- `ft_strdup`
- Bonus: `ft_list_size`

## 📦 Prerequisites

- Linux environment (x86_64)
- `nasm`
- `gcc`
- `make`
- `ar` (usually available with `binutils`)

## 🚀 Usage

Build the library:

```bash
make
```

Build with bonus:

```bash
make bonus
```

Run the main tests:

```bash
make run
```

Run the bonus list-size test:

```bash
make run2
```

Clean object files:

```bash
make clean
```

Remove objects and library:

```bash
make fclean
```
