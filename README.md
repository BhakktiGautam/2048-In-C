# 🎮 2048 Game in C

A simple console-based implementation of the classic **2048 game** written in C.

---

## 🚀 Features

* ✅ 4x4 Grid gameplay
* ✅ Random tile generation (2 or 4)
* ✅ Movement controls (W, A, S, D)
* ✅ Tile merging logic
* ✅ Score tracking system
* ✅ Win condition (2048 tile)
* ✅ Game Over detection

---

## 🕹️ Controls

| Key | Action     |
| --- | ---------- |
| W   | Move Up    |
| A   | Move Left  |
| S   | Move Down  |
| D   | Move Right |

---

## 🧠 Game Logic

* Tiles slide in the chosen direction.
* Adjacent equal tiles merge into one.
* After every valid move, a new tile (2 or 4) appears randomly.
* Score increases when tiles merge.
* Game ends when:

  * No empty cells AND
  * No adjacent equal tiles exist.

---

## 📦 How to Run

### 1. Compile the code

```bash
gcc main.c -o game
```

### 2. Run the game

```bash
./game
```

---

## 📸 Sample Output

```
SCORE: 4

-----------------------------
|   2|   2|    |    |
-----------------------------
|    |    |    |    |
-----------------------------
|    |    |    |    |
-----------------------------
|    |    |    |    |
-----------------------------
```

---

## 🏆 Winning Condition

Reach the **2048 tile** to win the game.

---

## ❌ Game Over Condition

* No empty cells left
* No possible merges

---

## 🔧 Future Improvements

* 🎨 Colored UI (better console design)
* 💾 High score saving
* ↩️ Undo feature
* 🤖 AI auto-play

---

## 👨‍💻 Author

* Your Name
Bhakkti Gautam

## ⭐ If you like this project

Give it a ⭐ on GitHub!
