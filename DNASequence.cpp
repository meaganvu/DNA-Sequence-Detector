#include <iostream>
using namespace std;
string find_overlap(string dna[],int size){
  string overall = dna[0];
  dna[0] = " ";
  int counterfill = 0;
  while (counterfill != size){
  counterfill = 0;
  string compare;
  for (int j = 1; j < size; j++){
    int overlap_back = 0;
    int overlap_front = 0;
    compare = dna[j];
    int length = 0;
    int copy = 10;
    int c = compare.length() - 10;
    int d = overall.length() - 10;
    while ((length < compare.length())&&(length < overall.length())){
      int b = 0;
        int counter=0;
          for (int k = c; k < compare.length(); k++){
            if (compare[k] == overall[b]){
              counter++;}
              b++;
            }
          if (counter == copy){
            overlap_back = counter;
          }
          copy ++;
          c--;
          length ++;
      }
      length = 0;
      copy = 10;
      while ((length < compare.length())&&(length < overall.length())){
        int b = 0;
        int counter=0;
            for (int k = d; k < overall.length(); k++){
              if (overall[k] == compare[b]){
                counter++;}
                b++;
              }
            if (counter == copy){
              overlap_front = counter;
          }
            copy ++;
            d--;
            length ++;
          }
      if (overlap_back > 10){
      string temp;
      for (int t = 0; t < compare.length() - overlap_back; t++ ){
        temp += compare[t];
      }
      overall = temp + overall;
      dna[j] = " ";
 }
    else if (overlap_front > 10){
      string temp;
      for (int t = 0; t < overall.length() - overlap_front; t++ ){
        temp += overall[t];
      }
      overall = temp + compare;
      dna[j] = " ";
    }
}
  for (int p = 0; p <size; p++){
    if (dna[p] == " "){
      counterfill++;
    }
  }
}
return overall;
}


int main(){
string dna[13] = {"AAAATCGATAGGAGATGGGATCCCATAGCCTACTAGCTACGATGCTACGTAGCTGCTAGCTATACTACTACGGCACGATCTAC","ATTAGCACCAGTACACGGTATGTGCATGATCTGACTAGTGTCT","GACTAATTTCTATTTCGACAAAATCGACGCTATATCCGATATTAGCGACCCATCTACGGATATCGCATATCGA","CGATCTATCTAGCATTCTCTTTCATCTAGCGACTA","ACACGGTATGTGCATGATCTGACTAGTGTCTGGGATTAGCCTCGATCGTGCCTGGGATCGATCGAGTAGC","ACGGCACGATCTACTACGAGCTGACTAGCTACGCCGCGGGCGCGCGCATCGTACATATATATCGCGATCTATCTAGCATTC","AGCGACCCATCTACGGATATCGCATATCGAGCGCGCATCTAGCTACGTAGTGATCGCTGA","CATCTAGCGACTAATTTCTATTTCGACAAAATCGACGCTATATCCGATATT","TGGGATCGATCGAGTAGCTTGCATCGATCGATTAG","TTAGCTAGATCGATACTGCCTAAGAGATCCTAGCTTTAGCTAGAGATCCCTGAATCGATTAGGGTTAGCTAAATAGTTCGATATTAGGCTAT","CTACGTAGTGATCGCTGACTAGCTAGGCTACGTCGATGCTAGCTTTATACGAGCTATATATCGATCGATGTATAAA","GATATTAGGCTATTAGAAAATCGATATAAAATCGATAGGAG","ATCGATCGATTAGCTAGATCGATACTGCCTAAGAGATCCTAGCTTTAGC"};
cout << find_overlap(dna, 13)<<endl;
return 0;
}
