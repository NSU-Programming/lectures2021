#include <memory>
#include <iostream>
#include <tuple>
#include <string>

using namespace std;

using Record = tuple<string, int, double>;

unique_ptr<Record> make_record() {
    return make_unique<Record>("Sam", 6, 4.1);
}

void process_record(unique_ptr<Record> rec) {
    auto [s, d, x] = *rec;
    cout << '[' << s << ", " << d << ", " << x << "]\n";
}

int main() {
    auto rptr = make_record();
    process_record(move(rptr));

    return 0;
}
