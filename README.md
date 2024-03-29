# ATM example for [cucumber_csteps](https://github.com/fooheads/cucumber_csteps)

Example adapted from [http://dannorth.net/whats-in-a-story/](http://dannorth.net/whats-in-a-story/)

The example uses [clib](https://github.com/clibs/clib) to track dependency of [assertion-macros.h](https://github.com/stephenmathieson/assertion-macros.h/)

Install the assertion-macros.h using

    $ make install-deps

Install cucumber_csteps and its dependencies:

    $ bundle install

Compile and run the specs (OS X):

    $ make features

On Linux you might need to set the LD_LIBRARY_PATH:

    $ LD_LIBRARY_PATH=. make features


## License

(The MIT License)

Copyright (c) 2015 Fooheads AB <hello@fooheads.com>

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
'Software'), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
