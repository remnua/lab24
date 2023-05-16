//Gym membership management system
//#include <iostream>
//#include <string>
//#include <vector>
//
//class GymMember {
//public:
//    int member_id;
//    std::string name;
//    int subscription_months;
//};
//
//class Gym {
//private:
//    std::vector<GymMember> members;
//
//public:
//    void createMember(int member_id, const std::string& name) {
//        if (members.size() >= 10) {
//            std::cout << "Cannot perform this operation: Maximum number of members reached." << std::endl;
//            return;
//        }
//
//        if (member_id == 0) {
//            std::cout << "Cannot perform this operation: Invalid member ID." << std::endl;
//            return;
//        }
//
//        for (const auto& member : members) {
//            if (member.member_id == member_id) {
//                std::cout << "Cannot perform this operation: Member ID already exists." << std::endl;
//                return;
//            }
//        }
//
//        GymMember new_member;
//        new_member.member_id = member_id;
//        new_member.name = name;
//        new_member.subscription_months = 0;
//        members.push_back(new_member);
//    }
//
//    void deleteMember(int member_id) {
//        if (member_id == 0) {
//            std::cout << "Cannot perform this operation: Invalid member ID." << std::endl;
//            return;
//        }
//
//        for (auto it = members.begin(); it != members.end(); ++it) {
//            if (it->member_id == member_id) {
//                members.erase(it);
//                return;
//            }
//        }
//
//        std::cout << "Cannot perform this operation: Member ID not found." << std::endl;
//    }
//
//    void extendSubscription(int member_id, int months) {
//        if (member_id == 0) {
//            std::cout << "Cannot perform this operation: Invalid member ID." << std::endl;
//            return;
//        }
//
//        for (auto& member : members) {
//            if (member.member_id == member_id) {
//                member.subscription_months += months;
//                return;
//            }
//        }
//
//        std::cout << "Cannot perform this operation: Member ID not found." << std::endl;
//    }
//
//    void cancelSubscription(int member_id) {
//        if (member_id == 0) {
//            std::cout << "Cannot perform this operation: Invalid member ID." << std::endl;
//            return;
//        }
//
//        for (auto& member : members) {
//            if (member.member_id == member_id) {
//                member.subscription_months = 0;
//                return;
//            }
//        }
//
//        std::cout << "Cannot perform this operation: Member ID not found." << std::endl;
//    }
//
//    void printMembers() {
//        if (members.empty()) {
//            std::cout << "No members in the system" << std::endl;
//        }
//
//        for (const auto& member : members) {
//            std::cout << "Member " << member.member_id << " : " << member.name
//                << ", subscription valid for " << member.subscription_months << " months" << std::endl;
//        }
//    }
//};
//
//int main() {
//    Gym gym;
//
//    while (true) {
//        std::string command;
//        std::getline(std::cin, command);
//
//        if (command == "create") {
//            int member_id;
//            std::string name;
//            std::cin >> member_id;
//            std::cin.ignore();
//            std::getline(std::cin, name);
//            gym.createMember(member_id, name);
//        }
//        else if (command == "delete") {
//            int member_id;
//            std::cin >> member_id;
//            gym.deleteMember(member_id);
//        }
//        else if (command == "extend") {
//            int member_id, months;
//            std::cin >> member_id >> months;
//            gym.extendSubscription(member_id, months);
//        }
//        else if (command == "cancel") {
//            int member_id;
//            std::cin >> member_id;
//            gym.cancelSubscription(member_id);
//        }
//        else if (command == "quit") {
//            break;
//        }
//        gym.printMembers();
//    }
//
//    return 0;
//}

#include <iostream>
#include <sstream>
#include <string>

class Fraction {
public:
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    std::string toString() {
        std::ostringstream oss;
        int wholePart = numerator / denominator;
        int remainder = numerator % denominator;

        if (remainder < 0) {
            remainder = -remainder;
        }

        if (wholePart != 0) {
            oss << wholePart << " ";
        }

        oss << remainder << "/" << denominator;
        return oss.str();
    }

    double toDouble() {
        return static_cast<double>(numerator) / denominator;
    }

private:
    int numerator;
    int denominator;
};

int main() {
    int num, den;
    std::string input;
    std::getline(std::cin, input);

    std::istringstream iss(input);
    iss >> num;
    iss.ignore(2); 
    iss >> den;

    Fraction fraction(num, den);
    std::cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << std::endl;

    return 0;
}
