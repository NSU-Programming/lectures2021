#include <memory>
#include <iostream>
#include <tuple>
#include <string>

using namespace std;

using Record = tuple<string, int, double>;

shared_ptr<Record> make_record() {
    return make_shared<Record>("Sam", 6, 4.1);
}

void process_record(shared_ptr<Record> rec) {
    auto [s, d, x] = *rec;
    cout << '[' << s << ", " << d << ", " << x << "]\n";
}

int main() {
    auto rptr = make_record();
    process_record(rptr);
    process_record(rptr);

    return 0;
}
