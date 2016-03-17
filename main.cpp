#include <iostream>

using namespace std;

int main()
{
    int num = 0;
    int key[64];

    int mrx[] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
    int mry[] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1};
    int mrz[] = {1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0};

    while(num < 64){



    int mrxOfXor = 0;
    int mryOfXor = 0;
    int mrzOfXor = 0;

    mrxOfXor = mrx[13] ^ mrx[16] ^ mrx[17] ^ mrx[18] ;

    mryOfXor = mry[20] ^ mry[21] ;

    mrzOfXor = mrz[7] ^ mrz[20] ^ mrz[21] ^ mrz[22];
int maj;
    if (mrx[8]+mry[10]+mrz[10] > 1)
    {
        maj = 1;
    }
    else
    {
        maj = 0;
    }


    if(maj == mrx[8])
    {
    //cout <<  "shift Mrs x" << endl;

    for(int i = 18;i>=0; i--){
    mrx[i] = mrx[i-1];
    }
    mrx[0] = mrxOfXor;

    }

    if(maj == mry[10])
    {
//    cout <<  "shift Mrs y";
    for(int i = 18;i>=0; i--){
    mry[i] = mry[i-1];
    }
    mry[0] = mryOfXor;

    }

    if(maj == mrz[10])
    {
 //   cout <<  "shift Mrs z" << endl;
    for(int i = 18;i>=0; i--){
    mrz[i] = mrz[i-1];
    }
    mrz[0] = mrzOfXor;

    }
    int XorOfLastBitOfthreeArray = mrx[18] ^ mry[21] ^ mrz[22];
  ///  for(int i = 0; i< 64; i++){
    key[num] = XorOfLastBitOfthreeArray;
    num++;
   }


    int data[64] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    cout << "Your Data : ";
    for(int i = 0;i<64; i++){
            cout << data[i];

            }
            cout << "\nYour Key : ";
   for(int i =0 ; i < 64; i++){
    cout <<
     key[i];
   }
   int cipher[64];
   for(int i =0 ; i < 64; i++){
   cipher[i] = data[i] ^ key[i];
   }
      cout << "\n Now Your Data : ";
    for(int i = 0;i<64; i++){
            cout << cipher[i];
    }
    for(int i =0 ; i < 64; i++){
   data[i] = cipher[i] ^ key[i];
   }
   cout << "\n real  Data : ";
    for(int i = 0;i<64; i++){
            cout << data[i];
    }

    return 0;
}



