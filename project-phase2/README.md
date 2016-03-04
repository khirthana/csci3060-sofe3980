Run using these commands:

clang++ -std=c++11 -stdlib=libc++ Account.h
clang++ -std=c++11 -stdlib=libc++ Account.cpp -c
clang++ -std=c++11 -stdlib=libc++ Utilities.h
clang++ -std=c++11 -stdlib=libc++ Utilities.cpp -c
clang++ -std=c++11 -stdlib=libc++ Account_Manager.h
clang++ -std=c++11 -stdlib=libc++ Account_Manager.cpp Accountsfile.txt TransactionLog.txt
