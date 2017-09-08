//Created By: April Browne
//Created On: 8/22/2016
 
 #include <iostream>
 using namespace std;
 
 struct monster{    //*struct occurs before int main so that compiler knows it's there
  string head;
  string eyes;
  string ears;
  string mouth;
  string nose;
 };
 
 int main()
 {
   monster monsterA;
   monsterA.head = "Zombus";            //?maybe make the user capable of setting their own attributes
   monsterA.eyes = "Vegitas";
   monsterA.ears = "Wackus";
   monsterA.nose = "Vegitas";
   monsterA.mouth = "Wackus";
   
   cout<<"Head:"<<monsterA.head<<endl;  //?add whitespace between operands and values
   cout<<"Eyes:"<<monsterA.eyes<<endl;
   cout<<"Ears:"<<monsterA.ears<<endl;
   cout<<"Nose:"<<monsterA.nose<<endl;
   cout<<"Mouth:"<<monsterA.mouth<<endl;
   
   monster monsterB;
   monsterB.head = "Zombus";
   monsterB.eyes = "Wackus";
   monsterB.ears = "Spritem";
   monsterB.nose = "Vegistas";
   monsterB.mouth = "Spritem";
   
   cout<<"Head:"<<monsterB.head<<endl;  //?add whitespace between operands and values
   cout<<"Eyes:"<<monsterB.eyes<<endl;
   cout<<"Ears:"<<monsterB.ears<<endl;
   cout<<"Nose:"<<monsterB.nose<<endl;
   cout<<"Mouth:"<<monsterB.mouth<<endl;
   
   //*add 'return 0;' here
 }