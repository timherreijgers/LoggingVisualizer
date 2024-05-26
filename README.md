# LoggingVisualizer
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=timherreijgers_LoggingVisualizer&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=timherreijgers_LoggingVisualizer)

LoggingVisualizer is a simple application to view log files. It aims to be 
efficient in loading and visualizing big files. Currently, it is pretty bare-bones due to the fact 
it's still in development.

## Current features
- Loading of files through the file menu and drag-and-drop
- Loading of log files with a specific format, where the date is interpreted as a string:
  - [date][level]Message

## Planned features:
- Highlighting of lines according to configurable colours and log level string
- Filtering of log messages
- Configurable log format
- Live updating of new lines in loaded log file
- Multiple different logging sources
  - Standard log files
  - Serial port
  - System messages
- Custom fields in log messages like, for example, source files, line, emitter, etc
- Visualizing log messages on a timeline
- Many, many more