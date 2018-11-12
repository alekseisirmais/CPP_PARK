#ifndef UserH
#define UserH

#include <fmx.h>

class User {
private:
	long long id;
	long long identificationKey;
	UnicodeString login;

public:
	User();
	~User();
	User(const User& other);
	User& operator=(const User& other);

	long long GetId();
	UnicodeString GetLogin();

	void SetId(const long long value);
	void SetIdKey(long long value);
	void SetLogin(UnicodeString loginStr);
};

#endif