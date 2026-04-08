# Tugas Struktur Data - Week 6 (2026)

**Nama:** Khalisya Zahra Putria Rahman

**NRP:** 5025251045

**Repository:** [Link Source Code]()

Repositori ini berisi penjelasan dan implementasi program C++ yang mendemonstrasikan **Aplikasi Penggunaan Stack**. Stack bekerja dengan prinsip **LIFO (Last In First Out)**, yang menjadikannya struktur data ideal untuk menyelesaikan permasalahan berbasis urutan dan penundaan eksekusi, seperti manipulasi dan evaluasi ekspresi matematika.

---

## 1. Konversi Infix ke Postfix

**Penjelasan:**
Ekspresi matematis yang biasa kita tulis (*infix*) seperti `A + B * C` perlu dikonversi ke bentuk *postfix* agar lebih mudah dievaluasi oleh mesin/komputer. Hal ini karena *postfix* tidak memerlukan tanda kurung dan menghormati prioritas operator secara alami. 

Dalam proses konversinya, Stack digunakan sebagai tempat penyimpanan sementara khusus untuk **operator** (`+`, `-`, `*`, `/`, `^`).

**Logika Algoritma:**
1. Baca ekspresi *infix* dari kiri ke kanan.
2. Jika yang dibaca **operand** (huruf/angka) → langsung masukkan ke *output*.
3. Jika yang dibaca **kurung buka `(`** → *push* ke dalam stack.
4. Jika yang dibaca **kurung tutup `)`** → *pop* isi stack ke *output* sampai `(` ditemukan, lalu buang `(`.
5. Jika yang dibaca **operator** → bandingkan prioritasnya. *Pop* operator di stack yang punya prioritas `≥` ke *output*, lalu *push* operator yang baru masuk ke stack.
6. Setelah selesai membaca ekspresi, *pop* semua sisa operator dari stack ke *output*.

**Kode C++:**
```cpp
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Fungsi untuk menentukan prioritas operator
int precedence(char op) {
    if (op == '^') return 3;
    else if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return 0;
}

// Fungsi untuk cek apakah karakter adalah operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Fungsi utama konversi infix ke postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // Jika operand (huruf/angka)
        if (isalnum(c)) {
            postfix += c;
        }
        // Jika '('
        else if (c == '(') {
            st.push(c);
        }
        // Jika ')'
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // hapus '('
        }
        // Jika operator
        else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop semua operator tersisa
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Masukkan ekspresi infix: ";
    cin >> infix;
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
    return 0;
}
```

---

## 2. Evaluasi Ekspresi Postfix 

**Penjelasan:**
Setelah mendapatkan bentuk *postfix*, langkah selanjutnya adalah mengevaluasinya untuk memperoleh nilai akhir. Pada proses ini, komputer membaca ekspresi dari kiri ke kanan. Stack digunakan untuk menyimpan angka sementara sambil menunggu operator yang tepat. Saat sebuah operator ditemukan, program akan menarik (`pop`) dua angka teratas dari stack, menghitungnya, lalu menaruh (`push`) hasilnya kembali ke stack.

**Kode C++ (Evaluasi Multi-Digit):**

```cpp
#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;
    stringstream ss(exp);
    string token;

    while (ss >> token) {
        // Jika operator
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            if (token == "+") st.push(val1 + val2);
            else if (token == "-") st.push(val1 - val2);
            else if (token == "*") st.push(val1 * val2);
            else if (token == "/") st.push(val1 / val2);
        }
        // Jika operand
        else {
            st.push(stoi(token));
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Masukkan postfix (pisahkan dengan spasi): ";
    getline(cin, postfix);
    cout << "Hasil: " << evaluatePostfix(postfix) << endl;
    return 0;
}
```

---

## 3. Visualisasi Stack

Visualisasi merupakan hal yang sangat penting untuk memahami secara utuh bagaimana elemen berpindah (`push` dan `pop`) di dalam Stack selama dua proses di atas. Berikut adalah ilustrasi kerja algoritmanya.

### A. Visualisasi Konversi Infix ke Postfix 
*Studi Kasus Ekpresi:* `A + B * C`

| Simbol yang Dibaca | Output (*String Postfix*) | Isi Stack (`top` di kanan) | Keterangan Eksekusi |
|--------------------|---------------------------|----------------------------|---------------------|
| `A` | `A` | `-` | Operand → langsung output |
| `+` | `A` | `+` | Operator → `push` ke stack |
| `B` | `A B` | `+` | Operand → langsung output |
| `*` | `A B` | `+ *` | Prioritas `*` > `+` → `push` ke stack |
| `C` | `A B C` | `+ *` | Operand → langsung output |
| *End* | **`A B C * +`** | `-` | `pop` semua sisa isi stack ke output |

### B. Visualisasi Proses Evaluasi Postfix 
*Studi Kasus Ekpresi:* `5 3 2 * +`

Proses ini menggambarkan aliran angka keluar dan masuk stack saat dievaluasi menjadi nilai akhir.

1. **READ `5`** → `push(5)`
   * `Stack: [5]`
2. **READ `3`** → `push(3)`
   * `Stack: [5, 3]`
3. **READ `2`** → `push(2)`
   * `Stack: [5, 3, 2]`
4. **READ `*`** → `pop` 2, `pop` 3. Hitung: `3 * 2 = 6` → `push(6)`
   * `Stack: [5, 6]`
5. **READ `+`** → `pop` 6, `pop` 5. Hitung: `5 + 6 = 11` → `push(11)`
   * `Stack: [11]`

**Hasil Akhir = 11** (Elemen satu-satunya yang tersisa di Stack).