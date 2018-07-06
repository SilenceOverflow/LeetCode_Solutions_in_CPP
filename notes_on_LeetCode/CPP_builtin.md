# C++ builtin funtions

### auto& vs auto
Yes, it is correct to use `auto` and `auto&` for local variables. When getting the return type of a function, it is also correct to use `auto&`. This applies for range based for loops as well.

General rules for using `auto` are:

Choose `auto x` when you want to work with copies.
Choose `auto &x` when you want to work with original items and may modify them.
Choose `auto const &x` when you want to work with original items and will not modify them.

### rand() and srand()
- srand((unsigned)time(NULL));  
- rand();
- refer to: https://blog.csdn.net/candyliuxj/article/details/4396666