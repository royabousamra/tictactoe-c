function winsplot()
%Plots the wins of all players in a pie chart

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
    X(n) = player(n).wins;
    Y(n) = player(n).fn;
end


H = pie(double(X));
title('Percentage of Total Wins of All Players');
T = H(strcmpi(get(H,'Type'),'text'));
P = cell2mat(get(T,'Position'));
set(T,{'Position'},num2cell(P*0.6,2))
text(P(:,1), P(:,2),Y(:),'FontSize',14)

end

