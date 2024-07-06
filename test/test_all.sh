#!/bin/bash -e

OUTDIR=bin
while IFS= read -r NAME; do
  echo $NAME
  $NAME
done < <(find ./$OUTDIR/*.test)
