#include<bits/stdc++.h>
using namespace std;

class Product{
    public :
        string pname;
        int price;
        int gst;
        int qty;
    Product(string st, int x, int y, int z){
        pname = st;
        price = x;
        gst = y;
        qty = z;
    }
    string getName() {
		return this->pname;
	}
	int getQty() {
		return this->qty;
	}
	int getgst() {
		return this->gst;
	}
    int getPrice(){
        return this->price;
    }
};
int main(){
    Product *p1 = new Product("Leather_Wallet", 1100, 18, 1);
    Product *p2 = new Product("Umbrella", 900, 12, 4);
    Product *p3 = new Product("Cigarette", 200, 28, 3);
    Product *p4 = new Product("Honey", 100, 0, 2);
    vector<Product *>shop;
    shop.push_back(p1);
    shop.push_back(p2);
    shop.push_back(p3);
    shop.push_back(p4);
    int maxm = 0;
    Product *maxmP;
    for(int i=0;i<shop.size();i++){
        Product *p = shop[i];
        int gstRate = p->getgst();
        double amount = gstRate * 0.01 * p->getPrice()*p->getQty(); 
        if(amount>maxm){
            maxm = amount;
            maxmP = shop[i];
        }
    }
    cout<<"Product for which we paid maximum GST amount is "<<maxmP->getName()<<endl;
    cout<<"\n";
    float totalPrice = 0;
    for(int i=0;i<shop.size();i++){
        Product *p = shop[i];
        totalPrice += p->getPrice()*p->getQty();
        if(p->getPrice() >= 500){
           totalPrice += p->getQty()*(p->getgst()-5)*0.01*p->getPrice();
        }
        else totalPrice += p->getQty()*p->getgst()*0.01*p->getPrice();
    }
    cout<<"Total Price is "<<totalPrice<<endl;
    return 0;
}
