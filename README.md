# Chatbot

A small console-based chatbot implemented in C++.

## Overview

This folder contains a simple chatbot implementation in `Chatbot.cpp`. A prebuilt `chatbot.exe` is included for Windows users.

## Requirements

- A C++ compiler (GCC, Clang, or MSVC)
- Make (optional)

## Build

Compile with g++ (example):

```
g++ -std=c++17 -O2 -o chatbot Chatbot.cpp
```

Or with MSVC (Developer Command Prompt):

```
cl /EHsc /O2 Chatbot.cpp /Fe:chatbot.exe
```

## Run

After building, run the executable:

Windows:

```
chatbot.exe
```

Linux / macOS:

```
./chatbot
```

Alternatively, use the included `chatbot.exe` on Windows.

## Files

- `Chatbot.cpp` — source code for the chatbot.
- `chatbot.exe` — prebuilt Windows executable (may be removed from repo if not desired).

## Notes

- This is a lightweight example meant for learning or extension. Feel free to refactor into multiple files, add a Makefile/CMakeLists, or expand bot logic.

