#include <iostream>

using namespace std;


char U[3][3] = { 
	{'w','w','w'},
	{'w','w','w'},
	{'w','w','w'}
};
char D[3][3] = { 
	{'y','y','y'},
	{'y','y','y'},
	{'y','y','y'} 
};

char F[3][3] = { 
	{'r','r','r'},
	{'r','r','r'},
	{'r','r','r'}
};
char B[3][3] = { 
	{'o','o','o'},
	{'o','o','o'},
	{'o','o','o'}
};

char L[3][3] = { 
	{'g','g','g'},
	{'g','g','g'},
	{'g','g','g'} 
};
char R[3][3] = { 
	{'b','b','b'},
	{'b','b','b'},
	{'b','b','b'}
};

/*
	U: 윗 면, D: 아랫 면,   
	F: 앞 면, B: 뒷 면,     
	L: 왼쪽 면, R: 오른쪽   

	+ : 시계, - : 반시계
*/

void cube_reset() {
	
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) U[i][j] = 'w';
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) D[i][j] = 'y';
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) F[i][j] = 'r';
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) B[i][j] = 'o';
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) L[i][j] = 'g';
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) R[i][j] = 'b';

}

void clock_wise(char X[][3]) {
	
	char tmp1 = X[0][0];
	X[0][0] = X[2][0];
	X[2][0] = X[2][2];
	X[2][2] = X[0][2];
	X[0][2] = tmp1;

	char tmp2 = X[0][1];
	X[0][1] = X[1][0];
	X[1][0] = X[2][1];
	X[2][1] = X[1][2];
	X[1][2] = tmp2;
	
}

void counterclock_wise(char X[][3]) {

	char tmp1 = X[0][0];
	X[0][0] = X[0][2];
	X[0][2] = X[2][2];
	X[2][2] = X[2][0];
	X[2][0] = tmp1;

	char tmp2 = X[0][1];
	X[0][1] = X[1][2];
	X[1][2] = X[2][1];
	X[2][1] = X[1][0];
	X[1][0] = tmp2;
	
}

void f(char side, char op) {
	switch (side)
	{
	case 'U': // FBLR move, 
		if (op == '+') { //F<-R<-B<-L<-F
			char tmp1 = F[0][0];
			char tmp2 = F[0][1];
			char tmp3 = F[0][2];

			F[0][0] = R[0][0];
			F[0][1] = R[0][1];
			F[0][2] = R[0][2];

			R[0][0] = B[0][0];
			R[0][1] = B[0][1];
			R[0][2] = B[0][2];

			B[0][0] = L[0][0];
			B[0][1] = L[0][1];
			B[0][2] = L[0][2];

			L[0][0] = tmp1;
			L[0][1] = tmp2;
			L[0][2] = tmp3;


			clock_wise(U);

		}
		else {//F<-L<-B<-R<-F
			char tmp1 = F[0][0];
			char tmp2 = F[0][1];
			char tmp3 = F[0][2];

			F[0][0] = L[0][0];
			F[0][1] = L[0][1];
			F[0][2] = L[0][2];

			L[0][0] = B[0][0];
			L[0][1] = B[0][1];
			L[0][2] = B[0][2];

			B[0][0] = R[0][0];
			B[0][1] = R[0][1];
			B[0][2] = R[0][2];

			R[0][0] = tmp1;
			R[0][1] = tmp2;
			R[0][2] = tmp3;
			
			counterclock_wise(U);
		}

		break;
	case 'D':
		if (op == '+') {//F<-L<-B<-R<-F
			char tmp1 = F[2][0];
			char tmp2 = F[2][1];
			char tmp3 = F[2][2];

			F[2][0] = L[2][0];
			F[2][1] = L[2][1];
			F[2][2] = L[2][2];

			L[2][0] = B[2][0];
			L[2][1] = B[2][1];
			L[2][2] = B[2][2];

			B[2][0] = R[2][0];
			B[2][1] = R[2][1];
			B[2][2] = R[2][2];

			R[2][0] = tmp1;
			R[2][1] = tmp2;
			R[2][2] = tmp3;
			clock_wise(D);
		}
		else {//F<-R<-B<-L<-F
			char tmp1 = F[2][0];
			char tmp2 = F[2][1];
			char tmp3 = F[2][2];

			F[2][0] = R[2][0];
			F[2][1] = R[2][1];
			F[2][2] = R[2][2];

			R[2][0] = B[2][0];
			R[2][1] = B[2][1];
			R[2][2] = B[2][2];

			B[2][0] = L[2][0];
			B[2][1] = L[2][1];
			B[2][2] = L[2][2];

			L[2][0] = tmp1;
			L[2][1] = tmp2;
			L[2][2] = tmp3;
			counterclock_wise(D);
		}
		break;

	case 'F': //URDL
		if (op == '+') {//U<-L<-D<-R<-TMP

			char tmp1 = U[2][0];
			char tmp2 = U[2][1];
			char tmp3 = U[2][2];

			U[2][0] = L[2][2];
			U[2][1] = L[1][2];
			U[2][2] = L[0][2];

			L[2][2] = D[2][0];
			L[1][2] = D[2][1];
			L[0][2] = D[2][2];

			D[2][0] = R[0][0];
			D[2][1] = R[1][0];
			D[2][2] = R[2][0];

			R[0][0] = tmp1;
			R[1][0] = tmp2;
			R[2][0] = tmp3;

			clock_wise(F);
		}
		else {//U<-R<-D<-L<-TMP
			
			char tmp1 = U[2][0];
			char tmp2 = U[2][1];
			char tmp3 = U[2][2];

			U[2][0] = R[0][0];
			U[2][1] = R[1][0];
			U[2][2] = R[2][0];

			R[0][0] = D[2][0];
			R[1][0] = D[2][1];
			R[2][0] = D[2][2];

			D[2][0] = L[2][2];
			D[2][1] = L[1][2];
			D[2][2] = L[0][2];

			L[2][2] = tmp1;
			L[1][2] = tmp2;
			L[0][2] = tmp3;

			counterclock_wise(F);
		}
		break;

	case 'B': //URDL
		if (op == '+') {//U<-R<-D<-L<-TMP
			char tmp1 = U[0][0];
			char tmp2 = U[0][1];
			char tmp3 = U[0][2];

			U[0][0] = R[0][2];
			U[0][1] = R[1][2];
			U[0][2] = R[2][2];

			R[0][2] = D[0][0];
			R[1][2] = D[0][1];
			R[2][2] = D[0][2];

			D[0][0] = L[2][0];
			D[0][1] = L[1][0];
			D[0][2] = L[0][0];

			L[2][0] = tmp1;
			L[1][0] = tmp2;
			L[0][0] = tmp3;
			clock_wise(B);
		}
		else {//U<-L<-D<-R<-TMP
			char tmp1 = U[0][0];
			char tmp2 = U[0][1];
			char tmp3 = U[0][2];

			U[0][0] = L[2][0];
			U[0][1] = L[1][0];
			U[0][2] = L[0][0];

			L[2][0] = D[0][0];
			L[1][0] = D[0][1];
			L[0][0] = D[0][2];

			D[0][0] = R[0][2];
			D[0][1] = R[1][2];
			D[0][2] = R[2][2];

			R[0][2] = tmp1;
			R[1][2] = tmp2;
			R[2][2] = tmp3;
			counterclock_wise(B);
		}
		break;

	case 'L':
		if (op == '+') {//U<-B<-D<-F<-U
			char tmp1 = U[0][0];
			char tmp2 = U[1][0];
			char tmp3 = U[2][0];

			U[0][0] = B[2][2];
			U[1][0] = B[1][2];
			U[2][0] = B[0][2];

			B[2][2] = D[2][2];
			B[1][2] = D[1][2];
			B[0][2] = D[0][2];

			D[2][2] = F[0][0];
			D[1][2] = F[1][0];
			D[0][2] = F[2][0];

			F[0][0] = tmp1;
			F[1][0] = tmp2;
			F[2][0] = tmp3;
			clock_wise(L);
		}
		else {//U<-F<-D<-B<-U
			char tmp1 = U[0][0];
			char tmp2 = U[1][0];
			char tmp3 = U[2][0];

			U[0][0] =  F[0][0];
			U[1][0] =  F[1][0];
			U[2][0] =  F[2][0];

			F[0][0] =  D[2][2];
			F[1][0] =  D[1][2];
			F[2][0] =  D[0][2];

			D[2][2] =  B[2][2];
			D[1][2] =  B[1][2];
			D[0][2] =  B[0][2];

			B[2][2] = tmp1;
			B[1][2] = tmp2;
			B[0][2] = tmp3;
			counterclock_wise(L);

		}
		break;

	case 'R': //UBDF
		if (op == '+') {//U<-F<-D<-B<-TMP
			char tmp1 = U[0][2];
			char tmp2 = U[1][2];
			char tmp3 = U[2][2];

			U[0][2] = F[0][2];
			U[1][2] = F[1][2];
			U[2][2] = F[2][2];

			F[0][2] = D[2][0];
			F[1][2] = D[1][0];
			F[2][2] = D[0][0];

			D[2][0] = B[2][0];
			D[1][0] = B[1][0];
			D[0][0] = B[0][0];

			B[2][0] = tmp1;
			B[1][0] = tmp2;
			B[0][0] = tmp3;
			clock_wise(R);
		}
		else {//U<-B<-D<-F<-TMP
			char tmp1 = U[0][2];
			char tmp2 = U[1][2];
			char tmp3 = U[2][2];

			U[0][2] = B[2][0];
			U[1][2] = B[1][0];
			U[2][2] = B[0][0];

			B[2][0] = D[2][0];
			B[1][0] = D[1][0];
			B[0][0] = D[0][0];

			D[2][0] = F[0][2];
			D[1][0] = F[1][2];
			D[0][0] = F[2][2];

			F[0][2] = tmp1;
			F[1][2] = tmp2;
			F[2][2] = tmp3;
			counterclock_wise(R);
		}
		break;
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string cmd;
			cin >> cmd;
			
			f(cmd[0], cmd[1]);
			/*
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) cout << U[i][j];
				cout << "\n";
			}
			cout << "\n";
			*/
		}

		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) cout << U[i][j];
			cout << "\n";
		}
		

		cube_reset();
	}

}


