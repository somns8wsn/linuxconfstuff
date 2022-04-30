#!/bin/bash

PS3='Choose game from "games" bottle: '
options=("Factorio" "Human Resources Machine" "Conolli_1" "Quit")
select opt in "${options[@]}"
do
	case $opt in
		"Factorio")
			echo "Factorio"
			flatpak run --command=bottles-cli com.usebottles.bottles run -b games -p factorio
			break
			;;
		"Human Resources Machine")
			echo "Human Resources Machine"
			flatpak run --command=bottles-cli com.usebottles.bottles run -b games -p Human\ Resource\ Machine
			break
			;;
		"Conolli_1")
			echo "Guns, Gore and Conolli 1"
			flatpak run --command=bottles-cli com.usebottles.bottles run -b games -p ggc
			break
			;;
		"Quit")
			break
			;;
		*) echo "invalid option $REPLY";;
	esac
done

