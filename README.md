# Minesweeper (C++ Console)

Minesweeper game implemented in C++ using console output with ANSI colors.

![Screenshot](screenshot.png)

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

## 🚀 Quick Start

### Prerequisites
- C++11 compiler (g++/clang++/MSVC)

### Build & Run
```bash
g++ -std=c++11 -Wall -o minesweeper minesweeper.cpp
./minesweeper  # Linux/Mac
minesweeper.exe  # Windows

## 🛠️ Compilation
 - -std=c++11 (required)
 - -Wall (recommended)
 - No dependencies

## 📸 Screenshots
<img width="1110" height="625" alt="Screenshot 2026-01-01 194613" src="https://github.com/user-attachments/assets/a1c2d9c9-71aa-4f71-8f77-cafc62ea3674" />
<img width="1108" height="623" alt="Screenshot 2026-01-01 194827" src="https://github.com/user-attachments/assets/ec2ff41a-e567-4a7f-8d33-c93e4d300cba" />
<img width="484" height="499" alt="Screenshot 2026-01-01 195127" src="https://github.com/user-attachments/assets/6368c4ea-2cbb-4427-99fc-9d84c43954df" />
<img width="671" height="482" alt="Screenshot 2026-01-01 194915" src="https://github.com/user-attachments/assets/3f4d2af8-b102-4f3d-9299-a31fa0285090" />

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

