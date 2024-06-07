#include <iostream>

using namespace std;

//  BÀI TOÁN NGƯỜI DU LỊCH

//Cho n thành phố đánh số từ 1 đến n và các đoạn đường 2 chiều giữa chúng, chi phí đi lại giữa các thành phố này được cho bởi
//mảng 2 chiều C[][], trong đó C[i][j] = C[j][i] là chi phí đi từ thành phố i đến thành phố j. 
//Chi phí giữa thành phố i đến chính nó bằng 0

//Một người du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại mỗi thành phố đúng 1 lần
//và cuối cùng quay lại thành phố 1. Hãy chỉ ra chi phí ít nhất mà người đó bỏ ra

//Input
//- Dòng đầu tiên là số nguyên n
//- n dòng sau, mỗi dòng chứa n số nguyên là chi phí giữa các thành phố

//Constraint:
//1 <= N <= 15
//0 <= C[i][j] <= 10^6

//Output: In ra chi phí nhỏ nhất của người đi du lịch

//Test case 1:
//Input:
// 3
// 0 46 94
// 46 6 42
// 94 42 0
//Output: 182

//Test case 2:
//Input:
// 4
// 0 85 26 81
// 85 0 77 97
// 26 77 0 26
// 81 97 26 0
//Output: 234

//  QUY HOẠCH ĐỘNG TẬP CON CÓ TỔNG BẰNG S

// Cho mảng số nguyên A gồm N phần tử và số nguyên dương 5, nhiệm vụ của bạn hãy xác định xem có thể tạo
// ra một tập con các phần tử trong mảng có tổng bằng 5 hay không? Chú ý mỗi phần tử trong màng chỉ được sử
// dụng một lần.

// Input Format

// Dòng đầu tiên gồm 2 số 1 và 5; Dòng thứ 2 gồm N số của mảng A

// Constraints

// 1<=N<=200; 1<=S<=50000; 1<=A[i]<=500

// Output Format

// In ra 1 nếu có tập con của A có tổng băng 5, ngược lại in ra 0

//  BÀI TOÁN DÃY CON TĂNG DÀI NHẤT

// Cho mảng số nguyên A gồm N phần tử, hãy tìm dãy con (không nhất thiết các phần tử phải liên tiếp) tăng
// chặt dài nhất của mảng A.

// Input Format

// Dòng đầu tiên là N; Dòng thứ 2 gồm N phần tử của mảng A;

// Constraints

// 1<=N<=1000; 1<=A[i]<=1000;

// Output Format

// In ra độ dài của dãy con tăng dài nhất


int main()
{

    return 0;
}