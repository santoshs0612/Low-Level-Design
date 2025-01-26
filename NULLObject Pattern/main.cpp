1 | #include <iostream>
2 | #include<bits/stdc++.h>
3 | using namespace std;
4 | ​
5 | //Interface 
6 | class Vehicle{
7 | ​
8 |   public:
9 |     virtual int getTankCapacity()=0;
10|     virtual int getSeatCapacity()=0;
11| };
12| ​
13| ​
14| class car:public Vehicle{
15|   public:
16|   int getTankCapacity(){
17|     return 50;
18|   }
19|   int getSeatCapacity(){
20|     return 5;
21|   }
22| };
23| ​
24| class NULLVehicle:public Vehicle{
25|   public:
26|   int getTankCapacity(){
27|     return 0;
28|   }
29|   int getSeatCapacity(){
30|     return 0;
31|   }
32| };
33| ​
34| class VehicleFactory:public Vehicle{
35|   public:
36|   static Vehicle* getVehicleObject(string type){
37|     if(type=="car"){
38|       car* carObje=new car();
39|       return carObje;
40|     }
41|     return new NULLVehicle();
42|   }
43| };
44| ​
45| ​
46| ​
47| ​
48| int main() { 
49|   
50|   Vehicle *vehicle;
51|   vehicle = VehicleFactory::getVehicleObject("bike");
52|   cout<<vehicle->getSeatCapacity()<<endl;
53|   cout<<vehicle->getTankCapacity()<<endl;
54| ​
55| ​
56| ​
57| }
