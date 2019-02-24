# IO Library

Buffer holds the data that the program reads and write.

Due to writting to system is time-comsuming, combine several output operation into a single write can  be performance boost.

## Buffer can be flushed in the following condition

1. Program completes notmally. All output are flushed.
2. When buffer become full
3. Flush buffer explicitly using manipulator `endl`
4. `unitbuf` manipulator to set the strea,'s internal state to empty the buffer after each output operation. `unitbuf` is set for `cerr`
5. Output stream tie to another stream that is being read or written.

`endl` -> new line and flush
`flush` -> no data and flush
`end2` -> null then flush

### `unitbuf` manipulator

 Flush after every output, with `unitbuf`
 `nounitbuf` restores the stream to use normal, system-managed buffer flushing.

`x.tie(&o)` ties the stream `x` to the output stream `o`

```c++
    cin.tie(&cout); //illustration only: the library ties cin and cout for us.
    //old_tie points to the stream currently tie to cin
    ostream *old_tie = cin.tie(nullptr); //cin no longer tie
    //tie cin and cerr; not good idea because cin should tie to cout
    cin.tie(&cerr); //reading cin flush cerr, not cout
    cin.tie(old.tie); //reestablish normal tie between cin and cout
```