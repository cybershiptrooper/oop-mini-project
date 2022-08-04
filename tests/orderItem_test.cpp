#include <iostream>
#include "orderItem.h"
#include "orderItemManager.h"
#include "orderItemParser.h"
#include "customer.h"
#include "product.h"
#include <assert.h>
#include <ctime>

/*bool testOrderItemClass(){
	cout << "Testing OrderItem Class\n";
	int id = 2;
    int qty = 1;
    int total = 100;
    Customer customer = Customer("custName", "custAddr", "1234567890");
	Product product = Product("prodName", 12);
    time_t curr_time;
    curr_time = time(NULL);
    char* tm = ctime(&curr_time);
    OrderItem order(id, &customer, &product, qty, tm, total);

	assert(id == order.getID());
    assert(&customer == order.getCustomer());
    assert(customer.getPhone()==order.getCustomer()->getPhone());
    assert(&product == order.getProduct());
    assert(product.getName()==order.getProduct()->getName());
    assert(qty == order.getQuantity());
    assert(tm == order.getTimeStamp());
    assert(total == order.getTotal());

    int newQty = 5;
	order.setQuantity(newQty);
    assert(newQty==order.getQuantity());
    Product newProd = Product("newProd", 15);
	order.setProduct(&newProd);
    assert(newProd.getName()==order.getProduct()->getName());
	cout << "OrderItem class test completed succesfully\n";
	return true;
}

bool testOrderItemPipeline(){
    testOrderItemClass();
}*/