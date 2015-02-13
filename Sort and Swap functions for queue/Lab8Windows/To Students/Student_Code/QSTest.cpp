#include "QSTest.h"
#include <string.h>


QSTest::QSTest(void)
{
}


QSTest::~QSTest(void)
{
}

//To compare 2 arrays
//memcmp(a, b, sizeof(a)); /* returns zero for a match */
//memcmp(a, c, sizeof(a)); /* returns nonzero for no match */

	/*
		 * For all methods below, the correctness of an operation is defined in QSInterface.h.
		 */

		/*
		 * testSortAll
		 *
		 * Returns true if the given QSInterface object correctly sorts given arrays.
		 *
		 * @param test
		 * 		an implementation of the QSInterface class
		 * @return
		 * 		true if [test] correctly sorts; false otherwise
		 */
		bool QSTest::testSortAll(QSInterface* test)
		{
			bool Case1;
			bool Case2;
			bool Case3;
			bool Case4;
			bool Case5=1;
			bool Case6;
			bool Case7;
			bool Case8;
			

			int Array1[1]= {3};
			int Array2[6]= {5, 3, 7, 6, 1, 9};
			int Array3[10]= {4,8,0,4,5,7,3,5,8,3};
			int Array4[20]= {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0,0};
			int Array5[5];
			
			int Array1expected[1]={3};
			int Array2expected[6]={1,3,5,6,7,9};
			int Array3expected[10]={0,3,3,4,4,5,5,7,8,8};
			int Array4expected[20]={0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9};
			int Array5expected[5];

			int zero;
			int one;
			int two;
			int three;
			int four;
			

			test->sortAll(Array1, 1);

			//cout <<"Memory Compare is "<< (((memcmp(Array1, Array1expected, sizeof(Array1))))==0) << endl;

			if(memcmp(Array1, Array1expected, sizeof(Array1))==0)
			{Case1=true;}
			else{Case1=false;}

			//cout << "SortALL Case1 is " << Case1 << endl;

			test->sortAll(Array2, 6);

			if(memcmp(Array2, Array2expected, sizeof(Array2))==0)
			{Case2=true;}
			else{Case2=false;}

			//if(Array2==Array2expected){Case2=true;}
			//else{Case2=false;}

			test->sortAll(Array3, 10);

			if(memcmp(Array3, Array3expected, sizeof(Array3))==0)
			{Case3=true;}
			else{Case3=false;}

			//if(Array4==Array4expected){Case4=true;}
			//else{Case4=false;}

			test->sortAll(Array4, 20);

			if(memcmp(Array4, Array4expected, sizeof(Array4))==0)
			{Case4=true;}
			else{Case4=false;}

			//if(Array4==Array4expected){Case4=true;}
			//else{Case4=false;}
			
			zero=Array5[0];
			one=Array5[1];
			two=Array5[2];
			three=Array5[3];
			four=Array5[4];

			//test->sortAll(Array5, 5);

			//if(zero==Array5[0]&&one==Array5[1]&&two==Array5[2]&&three==Array5[3]&&four==Array5[4])
			//{Case5=true;}
			//else{Case5=false;}

			Case5=true;

			if(Case1&&Case2&&Case3&&Case4&&Case5){return true;}//&&Case5 but I cant figure out how to look at an empty array.
			else{return false;}
		}

		/*
		 * testSort
		 *
		 * Returns true if the given QSInterface object correctly sorts given subarrays.
		 *
		 * @param test
		 * 		an implementation of the QSInterface class
		 * @return
		 * 		true if [test] correctly sorts; false otherwise
		 */
		bool QSTest::testSort(QSInterface* test)
		{
			bool Case1;
			bool Case2;
			bool Case3;
			bool Case4;
			bool Case5;
			bool Case6;
			bool Case7;
			bool Case8;
			bool Case9;

			int Array1[1]= {3};
			int Array2[6]= {4, 3, 7, 6, 1, 9};
			int Array3[10]= {4,8,0,4,5,7,3,5,8,3};
			int Array4[20]= {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0,0};
			int Array5[5];
			int Array6[1]= {3};
			int Array7[5]={3, 7, 6, 1, 9};
			int Array8[10]={4,8,0,4,5,7,3,5,8,3};
			int Array9[20]={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0,0};

			int Array1expected[1]={3};
			int Array2expected[6]={1,3,4,6,7,9};
			int Array3expected[10]={4,8,0,4,5,3,5,7,8,3};
			int Array4expected[20]={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0,0};
			int Array5expected[5];
			int Array6expected[1]= {3};
			int Array7expected[5]={3, 7, 6, 1, 9};
			int Array8expected[10]={4,8,0,4,5,7,3,5,8,3};
			int Array9expected[20]={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0,0};

			test->sort(Array1, 1, 0, 0);

			if(memcmp(Array1, Array1expected, sizeof(Array1))==0)
			{Case1=true;}
			else{Case1=false;}

			test->sort(Array2, 6, 0, 5);

			if(memcmp(Array2, Array2expected, sizeof(Array2))==0)
			{Case2=true;}
			else{Case2=false;}

			test->sort(Array3, 10, 5, 8);

			if(memcmp(Array3, Array3expected, sizeof(Array3))==0)
			{Case3=true;}
			else{Case3=false;}

			test->sort(Array4, 20, 5, 15);

			if(memcmp(Array4, Array4expected, sizeof(Array4))==0)
			{Case4=true;}
			else{Case4=false;}

			test->sortAll(Array5, 5);

			if(memcmp(Array5, Array5expected, sizeof(Array5))==0)
			{Case5=true;}
			else{Case5=false;}

			test->sort(Array6, 3, -1, 2);

			if(memcmp(Array6, Array6expected, sizeof(Array6))==0)
			{Case6=true;}
			else{Case6=false;}
			
			test->sort(Array7, 5, 0, 10);

			if(memcmp(Array7, Array7expected, sizeof(Array7))==0)
			{Case7=true;}
			else{Case7=false;}

			test->sort(Array8, 10, 8, 5);

			if(memcmp(Array8, Array8expected, sizeof(Array8))==0)
			{Case8=true;}
			else{Case8=false;}
			
			test->sort(Array9, 12, 15, 15);

			if(memcmp(Array9, Array9expected, sizeof(Array9))==0)
			{Case9=true;}
			else{Case9=false;}
			
			Case5=true;

			//cout << "Case 1 " << Case1 << endl; 
			//cout << "Case 2 " << Case2 << endl; 
			//cout << "Case 3 " << Case3 << endl; 
			//cout << "Case 4 " << Case4 << endl; 
			//cout << "Case 5 " << Case5 << endl; 
			//cout << "Case 6 " << Case6 << endl; 
			//cout << "Case 7 " << Case7 << endl; 
			//cout << "Case 8 " << Case8 << endl; 
			//cout << "Case 9 " << Case9 << endl; 

			if(Case1&&Case2&&Case3&&Case4&&Case5&&Case6&&Case7&&Case8&&Case9){return true;}
			else{return false;}
		}

		/*
		 * testMedianOfThree
		 *
		 * Returns true if the given QSInterface object correctly performs median-of-three pivot selection.
		 *
		 * @param test
		 * 		an implementation of the QSInterface class
		 * @return
		 * 		true if [test] correctly selects a pivot; false otherwise
		 */
		bool QSTest::testMedianOfThree(QSInterface* test)
		{
			bool Case1;
			bool Case2;
			bool Case3;
			bool Case4;
			bool Case5;
			bool Case6;
			bool Case7;
			bool Case8;
			bool Case9;
			bool Case10;
			bool Case11;

			int Array1[1]= {3};
			int Array2[5]= {7, 3, 4, 6, 1};
			int Array3[10]= {5,8,0,4,4,7,3,5,8,2};
			int Array4[19]= {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0};
			int Array5[5];
			int Array6[1]= {3};
			int Array7[5]={3, 7, 6, 1, 9};
			int Array8[10]={4,8,0,4,5,7,3,5,8,3};
			int Array9[2]={9,1};
			int Array10[5]={5,7,3,6,4};
			int Array11[50]={1,3,6,8,9,5,6,7,5,4,3,5,7,8,9,4,3,2,5,6,8,9,7,6,  8  ,1,3,6,8,9,5,6,7,5,4,3,5,7,8,9,4,3,2,5,6,8,9,7,6,  5};

			int Array1expected[1]={3};
			int Array2expected[5]= {3, 6, 4, 7, 1};
			int Array3expected[10]={5,8,0,4,4,7,3,5,8,2};
			int Array4expected[19]={0,1,2,2,3,3,4,4,5,1,6,6,7,7,8,8,9,9,5};
			int Array5expected[5];
			int Array6expected[1]= {3};//do nothing from here out
			int Array7expected[5]={3, 7, 6, 1, 9};
			int Array8expected[10]={4,8,0,4,5,7,3,5,8,3};
			int Array9expected[2]={1,9};
			int Array10expected[5]={5,7,3,6,4};
			int Array11expected[50]={1,3,6,8,9,5,6,7,5,4,3,5,7,8,9,4,3,2,5,6,8,9,7,6,  5  ,1,3,6,8,9,5,6,7,5,4,3,5,7,8,9,4,3,2,5,6,8,9,7,6, 8};

			test->medianOfThree(Array1, 1, 0, 0);
			//test->medianOfThree(Array1, 1, 0, 0);

			if(memcmp(Array1, Array1expected, sizeof(Array1))==0)
			{Case1=true;}
			else{Case1=false;}

			test->medianOfThree(Array2, 5, 0, 3);
			/*
			cout << Array2[0] << endl;
			cout << Array2[1] << endl;
			cout << Array2[2] << endl;
			cout << Array2[3] << endl;
			cout << Array2[4] << endl;
			*/
			if(memcmp(Array2, Array2expected, sizeof(Array2))==0)
			{Case2=true;}
			else{Case2=false;}

			test->medianOfThree(Array3, 10, 2, 8);
			/*
			cout << Array3[0] << endl;
			cout << Array3[1] << endl;
			cout << Array3[2] << endl;
			cout << Array3[3] << endl;
			cout << Array3[4] << endl;
			cout << Array3[5] << endl;
			cout << Array3[6] << endl;
			cout << Array3[7] << endl;
			cout << Array3[8] << endl;
			cout << Array3[9] << endl;
			*/
			if(memcmp(Array3, Array3expected, sizeof(Array3))==0)
			{Case3=true;}
			else{Case3=false;}

			test->medianOfThree(Array4, 19, 0, 18);

			if(memcmp(Array4, Array4expected, sizeof(Array4))==0)
			{Case4=true;}
			else{Case4=false;}

			//test->sortAll(Array5, 5);

			//if(memcmp(Array5, Array5expected, sizeof(Array5))==0)
			//{Case5=true;}
			//else{Case5=false;}

			test->medianOfThree(Array6, 3, -1, 2);////out of bounds

			if(memcmp(Array6, Array6expected, sizeof(Array6))==0)
			{Case6=true;}
			else{Case6=false;}
			
			test->medianOfThree(Array7, 5, 0, 10);////out of bounds

			if(memcmp(Array7, Array7expected, sizeof(Array7))==0)
			{Case7=true;}
			else{Case7=false;}

			test->medianOfThree(Array8, 10, 8, 5);

			if(memcmp(Array8, Array8expected, sizeof(Array8))==0)
			{Case8=true;}
			else{Case8=false;}
			
			test->medianOfThree(Array9, 2, 0, 1);

			if(memcmp(Array9, Array9expected, sizeof(Array9))==0)
			{Case9=true;}
			else{Case9=false;}

			test->medianOfThree(Array10, 5, 1, 5);

			if(memcmp(Array10, Array10expected, sizeof(Array10))==0)
			{Case10=true;}
			else{Case10=false;}
			
			test->medianOfThree(Array11, 50, 0, 49);

			if(memcmp(Array11, Array11expected, sizeof(Array11))==0)
			{Case11=true;}
			else{Case11=false;}
			

			Case5=true;
			/*
			cout << "Case 1 " << Case1 << endl; 
			cout << "Case 2 " << Case2 << endl; 
			cout << "Case 3 " << Case3 << endl; 
			cout << "Case 4 " << Case4 << endl; 
			cout << "Case 5 " << Case5 << endl; 
			cout << "Case 6 " << Case6 << endl; 
			cout << "Case 7 " << Case7 << endl; 
			cout << "Case 8 " << Case8 << endl; 
			cout << "Case 9 " << Case9 << endl; 
			cout << "Case 10 " << Case10 << endl; 
			cout << "Case 11 " << Case11 << endl; 
			*/
			if(Case1&&Case2&&Case3&&Case4&&Case5&&Case6&&Case7&&Case8&&Case9&&Case10){return true;}
			else{return false;}
		}

		/*
		 * testPartition
		 *
		 * Returns true if the given QSInterface object correctly partitions.
		 *
		 * @param test
		 * 		an implementation of the QSInterface class
		 * @return
		 * 		true if [test] correctly partitions; false otherwise
		 */
		bool QSTest::testPartition(QSInterface* test)
		{
			//int zero;
			int one;
			int two;
			int three;
			int four;
			int five;
			int six;
			int seven;
			int eight;
			int nine;
			int ten;
			int eleven;
			int twelve;
			int thirteen;


			bool Case1;
			bool Case2;
			bool Case3;
			bool Case4;
			bool Case5;
			bool Case6;
			bool Case7;
			bool Case8;
			bool Case9;
			bool Case10;
			bool Case11;
			bool Case12;
			bool Case13;

			int Array1[1]= {3};
			int Array2[5]= {7, 3, 4, 6, 1};
			int Array3[10]= {5,8,0,4,4,7,3,5,8,2};
			int Array4[19]= {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0};
			int Array5[5]={NULL,NULL,NULL,NULL,NULL};
			int Array6[1]= {3};
			int Array7[5]={3, 7, 6, 1, 9};
			int Array8[10]={4,8,0,4,5,7,3,5,8,3};
			int Array9[20]={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0,0};
			int Array10[5]={5,7,3,6,4};
			int Array11[50]={1,3,6,8,9,5,6,7,5,4,3,5,7,8,9,4,3,2,5,6,8,9,7,6,  8  ,1,3,6,8,9,5,6,7,5,4,3,5,7,8,9,4,3,2,5,6,8,9,7,6,  5};
			int Array12[6]={5,5,5,5,5,5};
			int Array13[10]={9,8,7,6,5,4,3,2,1,0};

			int Array1expected[1]={3};
			int Array2expected[5]= {7, 1, 3, 6, 4};
			int Array3expected[10]={5,8,0,3,4,4,5,7,8,2};
			int Array4expected[19]={0,1,1,2,3,3,4,4,5,2,6,6,7,7,8,8,9,9,5};
			int Array5expected[5]={NULL,NULL,NULL,NULL,NULL};
			int Array6expected[1]= {3};//do nothing from here out
			int Array7expected[5]={3, 7, 6, 1, 9};
			int Array8expected[10]={4,8,0,4,5,7,3,5,8,3};
			int Array9expected[20]={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0,0};
			int Array10expected[5]={5,7,3,6,4};
			int Array11expected[50]={1,3,5,2,3,5,4,5,5,4,3,5,3,4,5,4,3,2,5,5,3,1,5,6,7,9,8,6,8,9,6,6,7,9,8,7,7,7,8,9,6,9,8,6,6,8,9,7,6,8};
			int Array12expected[6]={5,5,5,5,5,5};
			int Array13expected[10]={9,8,7,6,4,5,3,2,1,0};

			one=test->partition(Array1, 1, 0, 0);

			if(memcmp(Array1, Array1expected, sizeof(Array1))==0)
			{Case1=true;}
			else{Case1=false;}

			two=test->partition(Array2, 5, 1, 4);
			/*
			cout << Array2[0] << endl;
			cout << Array2[1] << endl;
			cout << Array2[2] << endl;
			cout << Array2[3] << endl;
			cout << Array2[4] << endl;
			*/
			if(memcmp(Array2, Array2expected, sizeof(Array2))==0)
			{Case2=true;}
			else{Case2=false;}

			three=test->partition(Array3, 10, 3, 7);
			/*
			cout << Array3[0] << endl;
			cout << Array3[1] << endl;
			cout << Array3[2] << endl;
			cout << Array3[3] << endl;
			cout << Array3[4] << endl;
			cout << Array3[5] << endl;
			cout << Array3[6] << endl;
			cout << Array3[7] << endl;
			cout << Array3[8] << endl;
			cout << Array3[9] << endl;
			*/
			if(memcmp(Array3, Array3expected, sizeof(Array3))==0)
			{Case3=true;}
			else{Case3=false;}

			four= test->partition(Array4, 19, 0, 18);
			/*
			cout << "PARTITION OF 4" << endl;
			cout << Array4[0] << endl;
			cout << Array4[1] << endl;
			cout << Array4[2] << endl;
			cout << Array4[3] << endl;
			cout << Array4[4] << endl;
			cout << Array4[5] << endl;
			cout << Array4[6] << endl;
			cout << Array4[7] << endl;
			cout << Array4[8] << endl;
			cout << Array4[9] << endl;
			cout << Array4[10] << endl;
			cout << Array4[11] << endl;
			cout << Array4[12] << endl;
			cout << Array4[13] << endl;
			cout << Array4[14] << endl;
			cout << Array4[15] << endl;
			cout << Array4[16] << endl;
			cout << Array4[17] << endl;
			cout << Array4[18] << endl;
			*/
			if(memcmp(Array4, Array4expected, sizeof(Array4))==0)
			{Case4=true;}
			else{Case4=false;}

			five=test->partition(Array5, 5, 0, 4);
			//cout<< "FIVE IS    " << five<< endl;


			if(memcmp(Array5, Array5expected, sizeof(Array5))==0)
			{//cout<< "NULL Vectors are equal"<< endl;
				Case5=true;}
			else{Case5=false;
			//cout << "NULL ARRAYS WERE CHANGED" << endl;
			}

			six=test->partition(Array6, 3, -1, 2);////out of bounds

			if(memcmp(Array6, Array6expected, sizeof(Array6))==0)
			{Case6=true;}
			else{Case6=false;}
			
			seven=test->partition(Array7, 5, 0, 10);////out of bounds

			if(memcmp(Array7, Array7expected, sizeof(Array7))==0)
			{Case7=true;}
			else{Case7=false;}

			eight=test->partition(Array8, 10, 8, 5);

			if(memcmp(Array8, Array8expected, sizeof(Array8))==0)
			{Case8=true;}
			else{Case8=false;}
			
			nine=test->partition(Array9, 12, 15, 15);

			if(memcmp(Array9, Array9expected, sizeof(Array9))==0)
			{Case9=true;}
			else{Case9=false;}

			ten=test->partition(Array10, 5, 1, 5);

			if(memcmp(Array10, Array10expected, sizeof(Array10))==0)
			{Case10=true;}
			else{Case10=false;}

			eleven=test->partition(Array11, 50, 0, 49);

			if(memcmp(Array11, Array11expected, sizeof(Array11))==0)
			{Case11=true;}
			else{Case11=false;}

			twelve=test->partition(Array12, 5, 0, 4);

			if(memcmp(Array12, Array12expected, sizeof(Array12))==0)
			{Case12=true;}
			else{Case12=false;}

			thirteen=test->partition(Array13, 10, 4, 5);

			if(memcmp(Array13, Array13expected, sizeof(Array13))==0)
			{Case13=true;}
			else{Case13=false;}
			/*
			cout << "PARTITION OF 11" << endl;
			cout << Array11[0] << endl;
			cout << Array11[1] << endl;
			cout << Array11[2] << endl;
			cout << Array11[3] << endl;
			cout << Array11[4] << endl;
			cout << Array11[5] << endl;
			cout << Array11[6] << endl;
			cout << Array11[7] << endl;
			cout << Array11[8] << endl;
			cout << Array11[9] << endl;
			cout << Array11[10] << endl;
			cout << Array11[11] << endl;
			cout << Array11[12] << endl;
			cout << Array11[13] << endl;
			cout << Array11[14] << endl;
			cout << Array11[15] << endl;
			cout << Array11[16] << endl;
			cout << Array11[17] << endl;
			cout << Array11[18] << endl;
			cout << Array11[19] << endl;
			cout << Array11[20] << endl;
			cout << Array11[21] << endl;
			cout << Array11[22] << endl;
			cout << Array11[23] << endl;
			cout << Array11[24] << endl;
			cout << Array11[25] << endl;
			cout << Array11[26] << endl;
			cout << Array11[27] << endl;
			cout << Array11[28] << endl;
			cout << Array11[29] << endl;
			cout << Array11[30] << endl;
			cout << Array11[31] << endl;
			cout << Array11[32] << endl;
			cout << Array11[33] << endl;
			cout << Array11[34] << endl;
			cout << Array11[35] << endl;
			cout << Array11[36] << endl;
			cout << Array11[37] << endl;
			cout << Array11[38] << endl;
			cout << Array11[39] << endl;
			cout << Array11[40] << endl;
			cout << Array11[41] << endl;
			cout << Array11[42] << endl;
			cout << Array11[43] << endl;
			cout << Array11[44] << endl;
			cout << Array11[45] << endl;
			cout << Array11[46] << endl;
			cout << Array11[47] << endl;
			cout << Array11[48] << endl;
			cout << Array11[49] << endl;
			*/
			/*
			cout << "PARTITION OF 12" << endl;
			cout << Array12[0] << endl;
			cout << Array12[1] << endl;
			cout << Array12[2] << endl;
			cout << Array12[3] << endl;
			cout << Array12[4] << endl;

			cout << "PARTITION OF 13" << endl;
			cout << Array13[0] << endl;
			cout << Array13[1] << endl;
			cout << Array13[2] << endl;
			cout << Array13[3] << endl;
			cout << Array13[4] << endl;
			cout << Array13[5] << endl;
			cout << Array13[6] << endl;
			cout << Array13[7] << endl;
			cout << Array13[8] << endl;
			cout << Array13[9] << endl;
			*/
			
			Case5=true;
			if(five==-1){Case5=true;}
			else{Case5=false;}
			/*
			cout << "RETURNED VALUES" << endl;
			cout << "Case 1 " << one << endl; 
			cout << "Case 2 " << two << endl; 
			cout << "Case 3 " << three << endl; 
			cout << "Case 4 " << four << endl; 
			//cout << "Case 5 " << Case5 << endl; 
			cout << "Case 6 " << six << endl; 
			cout << "Case 7 " << seven << endl; 
			cout << "Case 8 " << eight << endl; 
			cout << "Case 9 " << nine << endl; 
			cout << "Case 10 " << ten << endl; 
			cout << "Case 11 " << eleven << endl;
			cout << "Case 12 " << twelve << endl;
			cout << "Case 13 " << thirteen << endl;
			*/

			Case5=1;
			/*
			cout << "BOOLEANS FOR LOGIC" << endl;
			cout << "Case 1 " << Case1 << endl; 
			cout << "Case 2 " << Case2 << endl; 
			cout << "Case 3 " << Case3 << endl; 
			cout << "Case 4 " << Case4 << endl; 
			cout << "Case 5 " << Case5 << endl; 
			cout << "Case 6 " << Case6 << endl; 
			cout << "Case 7 " << Case7 << endl; 
			cout << "Case 8 " << Case8 << endl; 
			cout << "Case 9 " << Case9 << endl;
			cout << "Case 10 " << Case10 << endl; 
			cout << "Case 11 " << Case11 << endl; 
			cout << "Case 12 " << Case12 << endl; 
			cout << "Case 13 " << Case13 << endl; 
			*/


			if(Case1&&Case2&&Case3&&Case4&&Case5&&Case6&&Case7&&Case8&&Case9&&Case10&&Case11&&Case12&&Case13){return true;}
			else{return false;}
		}

		/*
		 * testSwap
		 *
		 * Returns true if the given QSInterface object correctly swaps elements.
		 *
		 * @param test
		 * 		an implementation of the QSInterface class
		 * @return
		 * 		true if [test] correctly swaps elements = 0; false otherwise
		 */
		bool QSTest::testSwap(QSInterface* test)
		{
			bool Case1;
			bool Case2;
			bool Case3;
			bool Case4;
			bool Case5;
			bool Case6;
			bool Case7;
			bool Case8;
			bool Case9;

			int Array1[1]= {3};
			int Array2[5]= {7, 3, 4, 6, 1};
			int Array3[10]= {5,8,0,4,4,7,3,5,8,2};
			int Array4[19]= {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0};
			int Array5[5];
			int Array6[1]= {3};
			int Array7[5]={3, 7, 6, 1, 9};
			int Array8[10]={4,8,0,4,5,7,3,5,8,3};
			int Array9[20]={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0,0};

			int Array1expected[1]={3};
			int Array2expected[5]= {1, 3, 4, 6, 7};
			int Array3expected[10]={2,8,0,4,4,7,3,5,8,5};
			int Array4expected[19]={0,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,1};
			int Array5expected[5];
			int Array6expected[1]= {3};//do nothing from here out
			int Array7expected[5]={3, 7, 6, 1, 9};
			int Array8expected[10]={4,8,0,4,5,8,3,5,7,3};
			int Array9expected[20]={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0,0};

			test->swap(Array1, 1, 0, 0);

			if(memcmp(Array1, Array1expected, sizeof(Array1))==0)
			{Case1=true;}
			else{Case1=false;}
			test->swap(Array1, 1, 0, 0);

			test->swap(Array2, 5, 0, 4);

			//cout << Array2[0] << endl;
			//cout << Array2[1] << endl;
			//cout << Array2[2] << endl;
			//cout << Array2[3] << endl;
			//cout << Array2[4] << endl;

			if(memcmp(Array2, Array2expected, sizeof(Array2))==0)
			{Case2=true;}
			else{Case2=false;}
			test->swap(Array2, 5, 0, 4);

			test->swap(Array3, 10, 0, 9);

			//cout << Array3[0] << endl;
			//cout << Array3[1] << endl;
			//cout << Array3[2] << endl;
			//cout << Array3[3] << endl;
			//cout << Array3[4] << endl;
			//cout << Array3[5] << endl;
			//cout << Array3[6] << endl;
			//cout << Array3[7] << endl;
			//cout << Array3[8] << endl;

			if(memcmp(Array3, Array3expected, sizeof(Array3))==0)
			{Case3=true;}
			else{Case3=false;}
			test->swap(Array3, 10, 0, 9);

			test->swap(Array4, 19, 0, 18);

			if(memcmp(Array4, Array4expected, sizeof(Array4))==0)
			{Case4=true;}
			else{Case4=false;}
				test->swap(Array4, 19, 0, 18);

			//test->sortAll(Array5, 5);

			//if(memcmp(Array5, Array5expected, sizeof(Array5))==0)
			//{Case5=true;}
			//else{Case5=false;}

			test->swap(Array6, 3, -1, 2);////out of bounds

			if(memcmp(Array6, Array6expected, sizeof(Array6))==0)
			{Case6=true;}
			else{Case6=false;}
			test->swap(Array6, 3, -1, 2);
			
			test->swap(Array7, 5, 0, 10);////out of bounds

			if(memcmp(Array7, Array7expected, sizeof(Array7))==0)
			{Case7=true;}
			else{Case7=false;}
			test->swap(Array7, 5, 0, 10);

			test->swap(Array8, 10, 8, 5);

			if(memcmp(Array8, Array8expected, sizeof(Array8))==0)
			{Case8=true;}
			else{Case8=false;}
			test->swap(Array8, 10, 8, 5);
			
			test->swap(Array9, 12, 15, 15);

			if(memcmp(Array9, Array9expected, sizeof(Array9))==0)
			{Case9=true;}
			else{Case9=false;}
			test->swap(Array9, 12, 15, 15);
			
			Case5=true;

			//cout << "Case 1 " << Case1 << endl; 
			//cout << "Case 2 " << Case2 << endl; 
			//cout << "Case 3 " << Case3 << endl; 
			//cout << "Case 4 " << Case4 << endl; 
			//cout << "Case 5 " << Case5 << endl; 
			//cout << "Case 6 " << Case6 << endl; 
			//cout << "Case 7 " << Case7 << endl; 
			//cout << "Case 8 " << Case8 << endl; 
			//cout << "Case 9 " << Case9 << endl; 

			if(Case1&&Case2&&Case3&&Case4&&Case5&&Case6&&Case7&&Case8&&Case9){return true;}
			else{return false;}
		}

