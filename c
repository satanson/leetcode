#!/usr/bin/perl -w
use strict;
use Getopt::Std;
our $opt_g;
getopts('g') or die "invalid argument";
my $SRC=join " ",map{m#.*/(\w*\.cpp)\z#;$1} grep {m#\.cpp\z#}@ARGV;
my $dbg="";
$dbg="dbg=1" if $opt_g;
print qq(make $dbg -B SRC="$SRC"),"\n";
system qq(make $dbg -B SRC="$SRC");
