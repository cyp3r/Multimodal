imdir = '/home/wdanilo/work/studia/6/multimodalne/projekt/Multimodal/movie_3_png'
ext = 'png'
filename = 'matlabavi'

filearray=dir([imdir filesep '*.' ext])
s=size(filearray,1)

frameind=0;
mv =struct('cdata',{}, 'colormap', {});
figure, h =gcf;

for i=1:s-50
    ['wykonano ' int2str(i/s*100) '%']
    frameind=frameind+1;
    % imgname=[imdir filesep filearray(i).name];
    imgname=[imdir filesep 'frame_' int2str(i) '.png'];
    im=imread(imgname) ;
    imshow(im);
    mv(frameind)=getframe(h);
end
close(h)

movie2avi(mv, [imdir filesep filename '.avi'], 'compression', 'None');