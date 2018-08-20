<div class="tweet-item">
	<div class="content-block">
		<div>
			<a href="https://twitter.com/<?= $tweet_item['screen_name'] ?>" target="_blank">
				<img class="avatar" src="<?= $tweet_item['profile_image_url']; ?>" alt=" <?= $tweet_item['name'] ?>">
				<div class="FullNameGroup">
					<strong class="fullname">
						<?= $tweet_item['name']; ?>		
					</strong>
				</div>
			</a>
		</div>
		<div>
			<span class="screen-name">@<?= $tweet_item['screen_name']; ?></span>
			<span class="date-created"><?= $tweet_item['time_ago']; ?></span>
		</div>
		<div class="text">
			<?= $tweet_item['text']; ?>
		</div>
	</div>	
</div>
