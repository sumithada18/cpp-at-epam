
#include <iostream>
using namespace std;

int main()
{
	int a[3][3] = {
		6, 2, 5,
		0, 1, 3,
		4, 9, 8
	};

	//In C, a 2D array is stored in a contiguous memory block.
	//printf("%p \n", a);
	//when we printf array name('a' in this case) it returns base address that is
	//address of the forst element - in case of 2D array - first element in 2D array is complete first row of 2D array

	//printf("%p \n", *a);

	//printf("%p \n", a[0]);

	//printf("%p \n", &a[0][0]);
	//above stmts prints same value -> base address
	//'a' is of type int (*)[3] (pointer to an array of 3 integers)

	/*

	a -> pointer to the first row(int (*)[3])
	a[0] -> first row itself, which is 1D array of 3 integers(int[3])
	&a[0] -> address of the first row

	*/

	//---------------------------------------------------------------------------

// 	int *p = a[0];

 	//printf("%p \n", p);
 	//printf("%d \n", *p);

// 	p++; //4 bytes gets added - moves to the next element(column) in the same row

	//printf("%p \n", p);
	//printf("%d \n", *p);

	//---------------------------------------------------------------------------


	//printf("%d \n", a[0][0]);
	//a[i][j] is same as *(*(a+i)+i); where i is 0 in this case, we can check:-
	//printf("%d \n", *(*(a+0)+0

// 	p=a[0];
// 	printf("%p \n", p); //suppose it's 10

// 	p=a[1];
// 	printf("%p \n", p); //then it would be 112

// 	p=a[2];
// 	printf("%p \n", p); //and it would be 124

 	//we can check by doing:-
// 	p=a[0];
// 	printf("%d \n", *p);
 	//make the p jump to the first element of next row
// 	p+=3;
// 	printf("%d \n", *p);

	//---------------------------------------------------------------------------

	//we can also do:
	//int (*ptr)[3] = a; // ptr is a pointer to an array of 3 integers

	//printf("%p \n", ptr);

	//ptr++; //moves to the next row, not next column

	//printf("%p \n", ptr);

	//---------------------------------------------------------------------------

    //in c++ 2d arrays works similarly to C. Since fixed size arrays are not felxible,
    //modern c++ uses: std::vector<T> ;
    
    //let's see dynamic 2D array:
    
    int rows, cols;
    cout << "enter rows and cols:" << endl;
    cin >> rows >> cols;
    
    int **table = new int*[rows];
    
    for(int i=0; i<rows; i++){
        *(table+i) = new int[cols];
    }
    
    table[1][2] = 88;
    cout << table[1][2] << endl;
    
    //now since we have use the array, we need to deallocate the m/m as well
    
    for(int i=0; i<rows; i++){
        delete[] *(table+i);
    }
    
    delete[] table;

    table = nullptr;
    
	return 0;
}