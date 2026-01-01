# Minesweeper (C++ Console)

Minesweeper game implemented in C++ using console output with ANSI colors.

![Screenshot](screenshots/screenshot.png)

## 🎮 Features
- 4 difficulty levels (Beginner/Intermediate/Expert/Custom)
- ANSI color-coded numbers (1=Blue, 2=Green, 3=Red, 4=Cyan)
- Flood fill for zero cells
- Chord functionality
- Win/Lose detection

## 📋 Controls
[row] [col] → Select cell
F → Flag as mine
C → Reveal/Chord cell

## ⚙️ Difficulty Levels
| Level | Size  | Mines |
|-------|-------|-------|
| 1     | 8x8   | 10    |
| 2     | 16x16 | 40    |
| 3     | 16x30 | 99    |
| 4     | Custom| ≤35%  |

## 🔍 Game Mechanics
- **First click**: Mines placed avoiding exact cell
- **Zero flood fill**: Auto-reveals adjacent zeros + border numbers
- **Chording**: C on revealed number → reveals unflagged neighbors
- **Win**: All non-mine cells revealed

## 📸 Screenshots
![menu](screenshots/levels.png)
![screenshot](screenshots/screenshot.png)
![game play](screenshots/gameplay.png)
![end screen](screenshots/endscreen.png)

## 🚀 Quick Start

### Prerequisites
- C++11 compiler (g++/clang++/MSVC)

### Build & Run
```bash
g++ -std=c++11 -Wall -o minesweeper minesweeper.cpp
./minesweeper  # Linux/Mac
minesweeper.exe  # Windows
```

## 🛠️ Compilation
 - -std=c++11 (required)
 - -Wall (recommended)
 - No dependencies

## Build outputs
*.exe
*.o
a.out
minesweeper
minesweeper.exe

## IDE
.vscode/
.idea/
*.swp

## OS
.DS_Store
Thumbs.db


