![image](https://github.com/gryrryfh/visual-programming/assets/50912987/16fda159-1022-4e6f-89cc-d7c7d4b91444)
```xaml
    <StackPanel Orientation="Horizontal" HorizontalAlignment="Left" VerticalAlignment="Top">
        <MenuBar>
            <MenuBarItem Title="File">
                <MenuFlyoutItem Text="Save"/>
            </MenuBarItem>
        </MenuBar>
    </StackPanel>
```
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/d96f6e2e-2899-4d0e-94a2-6c73bfdff266)
```xaml
    <Grid>
        <Grid.RowDefinitions>
            <RowDefinition Height="40" />
            <RowDefinition Height="60" />
        </Grid.RowDefinitions>
        <Grid.ColumnDefinitions>
            <ColumnDefinition Width="Auto" />
        </Grid.ColumnDefinitions>

        <Grid Grid.Row="0" Background="Gainsboro" CornerRadius="10">
            <MenuBar>
                <MenuBarItem Title="File">
                    <MenuFlyoutItem Text="Save"/>
                </MenuBarItem>
            </MenuBar>
        </Grid>
        <Grid Grid.Row="1" Padding="15">
            <TextBlock>You Clicked :</TextBlock>
        </Grid>
    </Grid>
```

