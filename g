#!/usr/bin/env bash
read -p "Enter commit " message
git add .
git commit -m "$message"
git push
