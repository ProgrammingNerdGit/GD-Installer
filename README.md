### v1.0.1

# how to use

go to releses and download the latest verion
to use make a text file and name it anything you want
open the text file and for every dependecy you want (a file you want do be installed when the file launches) make a new line and do `dep=[filename]` 
and if you want a batch script to run when you run the file do the same thing but replace `dep=[filename]` to `com=[command]`

## example

> config.txt
```
dep=file1.txt
dep=file2.txt
com=echo test >> file.vbs
com=start www.google.com
```

### any questions just ask =)


