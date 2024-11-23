# TODO´s

- [ ] Add testing
- [ ] Add colorization for user-defined areas in message section
- [x] Add documentation

## LogCraft v0.2.0

- [x] Implement file I/O functionality
  - [x] Write to file
  - [x] Track file size for logging
  - [x] Create timestamped log files
  - [x] Create new log files when maximum line count or file size is reached
- [x] Adding a callstack
  - [x] Saving callstack for user defined log types
  - [x] write callstack tree to console/file
    - [x] Console
    - [x] File
  - [x] Add numbers from witch line the child func was called
  - [x] Add user defined format for callstack output
- [x] Add DeInit() function
- [x] Add lc::Log() func without StringLiteral for label

## LogCtaft v0.3.0

- [ ] Add thread information to log msg´s
- [ ] Add Logging buffers for storing log msg´s
  - [ ] Filter options for log levels
  - [ ] Add max num off stored logs
- [x] Add max num of log files
  - [x] Del old log files
