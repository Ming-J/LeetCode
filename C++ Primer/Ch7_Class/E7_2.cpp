#include <iostream>
using namespace std;

struct Sales_data{
  string bookNo;
  unsigned int unit_sold = 0;
  double revenue = 0.0;

  Sales_data& combine(const Sales_data rhs){
    revenue += rhs.revenue;
    unit_sold += rhs.unit_sold;
    return *this;
  }

  string isbn() const{
    return bookNo;
  }
};

int main(){
  Sales_data total;
  if(cin>>total.bookNo>>total.unit_sold>>total.revenue){
    Sales_data trans;
    while(cin>>total.bookNo>>total.unit_sold>>total.revenue){
      if(total.bookNo == trans.bookNo){
	total.unit_sold += trans.unit_sold;
	total.revenue += trans.revenue;
      }else{
	cout<< total.bookNo << ' ' << total.unit_sold <<' '<<
	  total.revenue << endl;
	total = trans;
      }
    }
    cout<< total.bookNo << ' ' << total.unit_sold <<' '<<
      total.revenue << endl;
  }else{
    cerr <<"No Data?!" << endl;
    return -1;
  }
  return 0;
}
