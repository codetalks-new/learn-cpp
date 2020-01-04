#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

enum class OrderType { buy, sell };

const string orderTypeToText(OrderType type) {
  switch (type) {
    case OrderType::buy:
      return "买入订单";
    case OrderType::sell:
      return "卖出订单";
  }
}

class Transaction {
 public:
  Transaction() {}
  virtual const string& getOrderNo() const = 0;
  void logTransaction(const string& orderNo, OrderType orderType) const {
    cout << "创建订单号为:" << orderNo << ",类型:" << orderTypeToText(orderType)
         << endl;
  }
};

class BuyTransaction : public Transaction {
 private:
  const string orderNo;

 public:
  BuyTransaction(const string orderNo) : orderNo(orderNo) {
    logTransaction(orderNo, OrderType::buy);
  }
  virtual const string& getOrderNo() const override {
    return orderNo;
  };
};

int main(int argc, char const* argv[]) {
  BuyTransaction b("B202001");
  return 0;
}