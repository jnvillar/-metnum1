import csv
import sys
from sets import Set


input_path = sys.argv[1]
output_path = sys.argv[2]

cantFechas = -1
if (len(sys.argv) == 4):
	cantFechas = int(sys.argv[3])

with open(input_path,'rb') as csvfile,open(output_path,'w') as outfile:
	score_reader = csv.reader(csvfile,delimiter=',',skipinitialspace=True)
	# Skip the header
	teams = {}
	n_games = 0
	n_teams = 1
	# String with info of the games.

	out_str = ''
	for row in score_reader:
		#idTeam = 0
		if row[1] in teams:
			idTeam = teams[row[1]]
			
		else:
			teams[row[1]] = n_teams
			idTeam = n_teams
			n_teams = n_teams + 1

		if row[3] in teams:
			idTeam2 = teams[row[3]]
		else:
			teams[row[3]] = n_teams
			idTeam2 = n_teams
			n_teams = n_teams + 1

		if n_games == cantFechas:
			break

		n_games = n_games+1
		out_str = out_str + str(n_games) + ' ' + str(idTeam) + ' ' + row[2] + ' ' + str(idTeam2) + ' ' + row[4] + '\n'
	# Write number of teams and games
	outfile.write(str(len(teams)) + ' ' + str(n_games) + '\n')
	# Write games details
	outfile.write(out_str)

