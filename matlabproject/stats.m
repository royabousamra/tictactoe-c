function stats (firstName, lastName)

fid = fopen('/Users/royabs/NetBeansProjects/tictactoe-project/scores.txt');
line = fgetl(fid);
line = fgetl(fid);

i = 1;

while true
  line = fgetl(fid);
  if ~ischar(line); break; end  

  c = textscan(line, '%s %s %d %d %d %d');
  
  player(i).fn = c{1};
  player(i).ln = c{2};
  player(i).played = c{3};
  player(i).wins = c{4};
  player(i).loss = c{5};
  player(i).score = c{6};

  i=i+1;  
end

for n=1:(i-1)

  if(strcmp(firstName, player(n).fn) == 1 && strcmp(lastName, player(n).ln) == 1)
  break;
  endif
  
end

X = [player(n).played, player(n).wins, player(n).loss, player(n).score]; 
 % c = categorical({'#ofPlays','Wins','Losses', 'Score'});
% bar(c, double(X));
bar(double(X), 'c')
title('Statistics of player distributed over Number of Plays, Wins, Losses, and the final Score');

end
