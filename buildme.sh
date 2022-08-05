mkdir -p data
echo "checking files..."
test -e data/customer.data && echo "present" || echo "Name; Address; Phone; Membership;" > data/customer.data

test -e data/orderItem.data && echo "present" || echo "custPhone; prodName; quantity; time;" > data/orderItem.data

test -e data/product.data && echo "present" || echo "Name; Cost; Category; Stock;" > data/product.data
echo "all files checked"
mkdir -p build
cd build && cmake ..
make