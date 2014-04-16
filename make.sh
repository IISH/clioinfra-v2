#!/bin/bash
#
# build.sh [instance] [version (default "1.0")]
#
# Build the package.

# Ensure a non zero exit value to break the build procedure.
set -e

instance=$1
if [ -z "$instance" ] ; then
	echo "Need a name of the project build."
	exit -1
fi

version=$2
if [ -z "$version" ] ; then
	echo "Default version 1.0"
	version="1.0"
fi

makefile=$instance.make
revision=$(git rev-parse HEAD)
target=target/$instance-$version
expect=$target.tar.gz

echo "Build $expect from $makefile, revision $revision"

# Remove previous builds.
if [ -d target ] ; then
	rm -r target
fi

drush make --tar $makefile ./$target
if [ -f $expect ] ; then
	echo "Done."
	exit 0
else
	echo "Build failed. No file found at $target."
	exit -1
fi
