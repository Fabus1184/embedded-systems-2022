# Assignment 1


| I/O Controller | Register Address | Description                                                                                                                              |
| -------------- | ---------------- | ---------------------------------------------------------------------------------------------------------------------------------------- |
| LEDR 9-0       | `0xFF200000`     | 10 Bit write-only register </br> bits 0-9 correspond to LED 0-9                                                                          |
|                |                  |                                                                                                                                          |
| KEY 3-0        | `0xFF200050`     | 4 Bit read-only register </br> bits 0-3 correspond to state of KEY 0-3                                                                   |
|                | `0xFF200058`     | 4 Bit interrupt mask register </br> `1` = interrupt masked                                                                               |
|                | `0xFF20005C`     | 4 Bit edge capture register </br>  `1` = changed from `0` to `1` since last read </br> writing sets every bit to `0` & clears interrupts |

- `volatile` is used to force read/write operations so that the compiler does not optimize them away

- `int` may be of different sizes on different architectures and/or compilers, so `int32_t` is used to ensure that the variable is 32 bits