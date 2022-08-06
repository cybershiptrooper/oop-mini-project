mkdir -p data
echo "checking files..."
test -e data/customer.data && echo "present" || echo -n "Name; Address; Phone; Membership;" > data/customer.data

test -e data/orderItem.data && echo "present" || echo -n "custPhone; prodName; quantity; time;" > data/orderItem.data

test -e data/product.data && echo "present" || echo -n "Name; Cost; Category; Stock;" > data/product.data
echo "all files checked"
mkdir -p build
cd build && cmake ..
make -j4