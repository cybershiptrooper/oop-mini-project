#include "customer_test.cpp"
#include "product_test.cpp"
#include "iowriter_test.cpp"

int main(int argc, char const *argv[])
{
	testCustomerPipeline();
	testProductClass();
	testIOWriterClass();
	return 0;
}