/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <string>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case, N, total_mirror; // N is room size


	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);
	int xx[] = {0,-1,1,0};
	int yy[] = {1,0,0,-1};


	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		total_mirror = 0;
		cin >> N;

		int **Map = new int*[N];
		bool **isReflect = new bool*[N];
                
		for(int i = 0 ; i < N; i++){
			Map[i] = new int[N];
			isReflect[i] = new bool[N];
		}
	// 맵에 대한 데이터 동적할당	
		for(int i = 0 ; i < N; i++){
			string str;
			char temp[1];
			cin >> str;

			for(int j = 0 ; j < N ; j++){
				temp[0] = str[j];
				Map[i][j] = atoi(temp);
			}
		}
	//각 row에 해당하는 값을 정수로 변환하여 받음
	//sting 형태의 temp를 사용하여 받아서 stoi를 썻으나 코드 그라운드에서는 에러
		int current_dir = 1;

		int cx = 0, cy = 0;

		while(cx >= 0 && cy >= 0 && cx <=N-1 && cy <= N-1) {
                
                if(Map[cx][cy] == 1) {
                    if(current_dir % 2 == 1) current_dir++;
                    else current_dir--;
                }
		
		// 1번 거울 case

                else if(Map[cx][cy] == 2) {
                    current_dir +=2;
                    if(current_dir > 4) current_dir %= 4;
                }
                
		// 2번 거울 case

                if(!isReflect[cx][cy] && Map[cx][cy]!=0) {
                    isReflect[cx][cy] = true;
                    total_mirror++;
                }
		// 지나간 거울 수 계산
                
                cx += xx[current_dir-1];
                cy += yy[current_dir-1];
		// 빛이 빠져나가는 경우의 수 계산
            }
				
	

		Answer = total_mirror;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
