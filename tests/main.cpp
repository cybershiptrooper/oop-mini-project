#include "customer_test.cpp"
#include "productTest.cpp"
#include "iowriter_test.cpp"
#include "orderItem_test.cpp"

int main(int argc, char const *argv[])
{
	testCustomerPipeline();
	testProductClass();
	testIOWriterClass();
	//testOrderItemClass();
	//testOrderItemClass();
	return 0;
}