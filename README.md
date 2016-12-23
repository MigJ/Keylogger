# Mail Side

   ## How to use

   * The keylogger side must call this side with this prototype :
   ' int     store_send_input(char *key_logs) '
   * After that, the program is looking for {sudo/firefox} commands.
   * When one of those ones is find he store 50 to 500 letters in a log file
   * If the log file size is more than 5000 chars, it will send with send.py an email, with log file in attachment
     with the victim's name in subject
   * After sending, the program clear the log file, and wait for new inputs

  ----------------------------------------------------------------------------------------------------------------------


###### Todo :

       	    - [ ] add an array of functions's pointers to upgrade the system of listening of commands

   ######  More :

  * This program have been developped by me, and Miguel Joubert. *