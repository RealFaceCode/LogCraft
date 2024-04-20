# TODO´s

- [ ] Add testing

## LogCraft v0.2.0

- [ ] Implement file I/O functionality
  - [ ] Write to file
  - [ ] Track file size for logging
  - [ ] Create timestamped log files
  - [ ] Create new log files when maximum line count or file size is reached
- [ ] Adding a callstack
  - [x] Saving callstack for user defined log types
  - [ ] write callstack tree to console/file
    - [x] Console
    - [ ] File
  - [x] Add numbers from witch line the child func was called
  - [ ] Add user defined format for callstack output
- [x] Add DeInit() function
- [x] Add lc::Log() func without StringLiteral for label
- [ ] Add colorization for user-defined areas in message section

## LogCtaft v0.3.0

- [ ] Add thread information to log msg´s
- [ ] Add Logging buffers for storing log msg´s
  - [ ] Filter options for log levels
  - [ ] Add max num off stored logs
- [ ] Add max num of log files
  - [ ] Del old log files
