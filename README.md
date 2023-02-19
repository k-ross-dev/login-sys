# login-sys
This is a small simple login project. 

It was initially based on this idea (by Hazard Edit):

https://www.youtube.com/watch?v=I_aWPGCaaFA

However, I wanted to add a bit of encryption since the passwords are stored. 

## How it works
The encryption as it stands starts at registration when a username + password are given.

1. file name created using the username.
2. username and password written to file. 
3. that file is then taken character by character, and changed using the key.
4. the original file is deleted and we are left with a `username_enc.txt` file, indicating it is encrypted. 
5. When Login happens, the file checks the existence of the user's encoded file.
5a. if it exists, the file will decode and checks the password.
   5ab. If the password doesnt match, return false
5b. if it doesnt exist, the login fails.
6. regardless, the file is re-encrypted and the decoded one is deleted. 

