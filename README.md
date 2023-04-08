# >>>{Make Sure To Switch To the Proper Branch}<<<

Group Members:
  Alejandro Mora-Lopez,
  Angel Zuniga

* Wait Command Video: https://youtu.be/h8cVX5NaX7E
* Priority Command Video: https://youtu.be/boIz46NIDGc

## Contents of Branches
* `master` - base version of FreeNOS --> wait command and renice command/priority levels not implemented
* `wait` - implementation of wait command in base version of FreeNOS
* `priority` - impementation of process priority levels and renice command in FreeNOS, including wait command

## Contributions to Project
* Priority
  - Alejandro Mora-Lopez
    - Implemented Renice Command
    - Implemented the changing of the priority level of a process by ProcessManager
    - Fixed multiple bugs which caused FreeNOS to not run properly
  - Angel Zuniga
    - Changed ps application
    - Implemented the priority based scheduling with the count function in Scheduler    
