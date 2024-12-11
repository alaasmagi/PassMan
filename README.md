# PassMan - password manager 

## Description

* Uni project
* Task: to develop a password manager using C language
* UI language: Estonian
* Languages and technologies: **C & SQLite**
* Authors: Aleksander Laasmägi, Kristofer Mäeots, Eeva-Maria Tšernova
* Development place and year: **TalTech 2023**

## How to run

*  Download the folder corresponding to your preferred theme (dark mode or light mode).
*  The app runs on Linux. Both _plug-n-play_ folders have Linux executables for _plug-n-play_ experience.
*  Ensure your system supports GTK 3.0 and SQLite.

## Features
*  Quite secure storage and management of passwords.
*  Separate support for dark mode and light mode.
*  All sensitive data is protected using hashing and encryption.

## Application structure

### Frontend/UI
Frontend is developed using Glade (gtk 3.0).

### Database
*  Passwords are hashed using the SHA-256 algorithm.
*  Database files are encrypted using ccrypt.

### Security
Hashing functions are used to secure all sensitive content.

## Technical requirements
*  A Linux distribution with support for **GTK 3.0** and **SQLite**
*  No additional setup is needed; the application is ready to use out of the box.

## Possibilities for future enhancement
*  Cloud synchronization for password backup and sharing.
*  Two-factor authentication (2FA) support.

## Troubleshooting
If you encounter any issues:

*  Ensure your Linux system has GTK 3.0 installed.
*  Verify SQLite compatibility.
*  For additional support, contact the authors.

## Illustrative images
### Dark mode:
![Screenshot from 2023-04-28 13-02-16](https://github.com/user-attachments/assets/8cd87d20-6f16-4168-a58d-af10536be273)

### Light mode:
![Screenshot from 2023-04-28 13-13-01](https://github.com/user-attachments/assets/f76bfa2c-25dd-4f2c-bb92-2741104155c2)

## Detailed Documentation (In Estonian)
[Report_EST](https://github.com/user-attachments/files/18101110/Paroolihaldur_PassMan_aruanne.1.pdf)

