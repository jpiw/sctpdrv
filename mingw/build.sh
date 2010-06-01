#!/bin/sh

dlltool -k --add-stdcall-underscore --output-lib libsctpsp.a --def libsctpsp.def
