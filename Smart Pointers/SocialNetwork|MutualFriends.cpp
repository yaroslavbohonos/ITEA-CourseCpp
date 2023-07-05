/* Task in Replit(Compiler) - https://replit.com/@Bgns/Mutual-friends-for-user-or-75#main.cpp

Task: Create classes for objects needed in social networks.
1) Start with registered users (identifier, login, password, etc.).
2) Each user has added friends.
3) There are those who added the user as a friend.
4) Mutual friends class.

In the main program, create a list of registered users with 5-9 objects. For one of them, create a list of added friends with 3-4 objects.
A list of those who added the user as a friend with 3-4 objects and a list of mutual friends based on the previous two lists. 
Print the logins of users from all the lists sequentially on the screen.*/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

class RegisteredUser {
protected:
    static int staticId;
    int id;
    std::string login, password;
    std::vector<RegisteredUser*> usersFriends;
    std::vector<RegisteredUser*> friendsAddedUser;
    std::vector<RegisteredUser*> mutualFriends;
    std::vector<std::string> logins {"dog123", "helenjok", "jsdees", "katrin", "lola12", "denkey", "jonny1", "sally", "Lalli", "Shjek"};
    std::vector<std::string> passwords {"12345678", "87654321", "13572468"};

public:
    RegisteredUser() {
        login = logins[rand() % logins.size()];
        password = passwords[rand() % passwords.size()];
        id = staticId++;
    }

    int get_id() { return id; }

    void PrintInfo() {
        std::cout << "\nid: " << id << " \nlogin: " << login << std::endl;
    }

    void PrintUsersFriends() {
        for (const auto& friendUser : usersFriends)
            friendUser->PrintInfo();
        std::cout << "\n";
    }

    void PrintFriendsAddedUser() {
        for (const auto& friendAddedUser : friendsAddedUser)
            friendAddedUser->PrintInfo();
        std::cout << "\n";
    }

    void MakeFriendsList(std::vector<RegisteredUser*>& Users) {
        usersFriends.push_back(Users[0]);
        usersFriends.push_back(Users[1]);
        usersFriends.push_back(Users[8]);
        friendsAddedUser.push_back(Users[4]);
        friendsAddedUser.push_back(Users[5]);
        friendsAddedUser.push_back(Users[8]);
    }

    void CheckMutualFriends(const std::vector<RegisteredUser*>& MutualFriends) {
        std::cout << "\n\nMutual friend/-s:";
        for (const auto& mutualFriend : MutualFriends) {
            mutualFriend->PrintInfo();
        }
        std::cout << std::endl;
    }

    void MakeMutualFriends() {
        for (const auto& userFriend : usersFriends) {
            for (const auto& friendAddedUser : friendsAddedUser) {
                if (userFriend->get_id() == friendAddedUser->get_id()) {
                    mutualFriends.push_back(userFriend);
                }
            }
        }
        CheckMutualFriends(mutualFriends);
    }
};

void PrintInfo(const std::vector<RegisteredUser*>& Users) {
    for (const auto& user : Users)
        user->PrintInfo();
    std::cout << std::endl;
}

void CreateFriends(std::vector<RegisteredUser*>& Users) {
    int position = rand() % 8;
    Users[position]->MakeFriendsList(Users);
    std::cout << "\n\nAdded user's friends with id-" << position + 1 << ": ";
    Users[position]->PrintUsersFriends();
    std::cout << "\n\nWho added the user with id-" << position + 1 << ": ";
    Users[position]->PrintFriendsAddedUser();
    Users[position]->MakeMutualFriends();
}

int RegisteredUser::staticId = 1;

int main() {
    srand(time(NULL));
    int size = 9;
    std::vector<RegisteredUser*> Users(size);
    for (auto& user : Users)
        user = new RegisteredUser();

    std::cout << "Task: Create a list of registered users with 5-9 objects.\n"
          << "For one of them, create a list of added friends with 3-4 objects.\n"
          << "Create a list of users who added the user as a friend with 3-4 objects.\n"
          << "Create a list of mutual friends based on the previous two lists.\n"
          << "Print the logins of users from all the lists sequentially.\n";

    CreateFriends(Users);

    std::cout << "\nUsers:";
    PrintInfo(Users);

    for (auto& user : Users)
        delete user;

    return 0;
}
