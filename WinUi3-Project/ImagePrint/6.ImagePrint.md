![image](https://github.com/gryrryfh/visual-programming/assets/50912987/856c998e-b1fc-43aa-9493-709f6d7fd482)
```xaml
    <VariableSizedWrapGrid Orientation="Vertical" MaximumRowsOrColumns="2" ItemHeight="268" ItemWidth="400" HorizontalAlignment="Center" VerticalAlignment="Center">
        <Image>
            <Image.Source>
                <BitmapImage UriSource="https://github.com/microsoft/WinUI-Gallery/blob/main/WinUIGallery/Assets/SampleMedia/LandscapeImage1.jpg?raw=true"/>
            </Image.Source>
        </Image>
        <Image>
            <Image.Source>
                <BitmapImage UriSource="https://github.com/microsoft/WinUI-Gallery/blob/main/WinUIGallery/Assets/SampleMedia/LandscapeImage2.jpg?raw=true"/>
            </Image.Source>
        </Image>
        <Image>
            <Image.Source>
                <BitmapImage UriSource="https://github.com/microsoft/WinUI-Gallery/blob/main/WinUIGallery/Assets/SampleMedia/LandscapeImage3.jpg?raw=true"/>
            </Image.Source>
        </Image>
        <Image>
            <Image.Source>
                <BitmapImage UriSource="https://github.com/microsoft/WinUI-Gallery/blob/main/WinUIGallery/Assets/SampleMedia/LandscapeImage4.jpg?raw=true"/>
            </Image.Source>
        </Image>
    </VariableSizedWrapGrid>

</Window>
```
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/438146a3-1614-42b4-b958-83a12264e1b0)

```xaml
 <StackPanel Orientation="Horizontal" HorizontalAlignment="Center" VerticalAlignment="Center">
     <Image Width="450">
         <Image.Source>
             <BitmapImage UriSource="https://github.com/microsoft/WinUI-Gallery/blob/main/WinUIGallery/Assets/SampleMedia/LandscapeImage1.jpg?raw=true"/>
         </Image.Source>
     </Image>

         <Image Width="450">
             <Image.Source>
             <BitmapImage UriSource="https://github.com/microsoft/WinUI-Gallery/blob/main/WinUIGallery/Assets/SampleMedia/LandscapeImage2.jpg?raw=true"/>
         </Image.Source>
     </Image>

             <Image Width="450">
                 <Image.Source>
             <BitmapImage UriSource="https://github.com/microsoft/WinUI-Gallery/blob/main/WinUIGallery/Assets/SampleMedia/LandscapeImage3.jpg?raw=true"/>
         </Image.Source>
     </Image>

                 <Image Width="450">
                     <Image.Source>
             <BitmapImage UriSource="https://github.com/microsoft/WinUI-Gallery/blob/main/WinUIGallery/Assets/SampleMedia/LandscapeImage4.jpg?raw=true"/>
         </Image.Source>
     </Image>
 </StackPanel>
```
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/d0442d6d-de5c-42eb-b2d5-7b9572377db4)
```xaml
    <Grid ColumnSpacing ="5" RowSpacing="5"  HorizontalAlignment="Center" VerticalAlignment="Center">
        <Grid.RowDefinitions>
            <RowDefinition Height="60"/>
            <RowDefinition Height="590"/>
        </Grid.RowDefinitions>
        <Grid.ColumnDefinitions>
            <ColumnDefinition Width="600"/>
            <ColumnDefinition Width="400"/>
        </Grid.ColumnDefinitions>

        <Image Grid.Column="0" Grid.Row="0">
            <Image.Source>
                <BitmapImage UriSource="https://github.com/microsoft/WinUI-Gallery/blob/main/WinUIGallery/Assets/SampleMedia/LandscapeImage1.jpg?raw=true"/>
            </Image.Source>
        </Image>

        <Image Grid.Column="1" Grid.Row="0">
            <Image.Source>
                <BitmapImage UriSource="https://github.com/microsoft/WinUI-Gallery/blob/main/WinUIGallery/Assets/SampleMedia/LandscapeImage2.jpg?raw=true"/>
            </Image.Source>
        </Image>

        <Image Grid.Column="0" Grid.Row="1">
            <Image.Source>
                <BitmapImage UriSource="https://github.com/microsoft/WinUI-Gallery/blob/main/WinUIGallery/Assets/SampleMedia/LandscapeImage3.jpg?raw=true"/>
            </Image.Source>
        </Image>

        <Image Grid.Column="1" Grid.Row="1">
            <Image.Source>
                <BitmapImage UriSource="https://github.com/microsoft/WinUI-Gallery/blob/main/WinUIGallery/Assets/SampleMedia/LandscapeImage4.jpg?raw=true"/>
            </Image.Source>
        </Image>
    </Grid>
```
